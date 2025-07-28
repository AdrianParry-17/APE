#ifndef __APE_BUILDER_H__
#define __APE_BUILDER_H__

namespace APE {
    /// @brief The IBuilder template, provide a base class template of APE builder.
    /// @tparam ResultT The type of the result object to build.
    template <typename ResultT>
    class IBuilder {
        virtual ResultT Build() = 0;
    };

    /// @brief The IObjectBuilder template, provide an interface to create an object builder.
    /// @tparam ObjectT The type of the object to build.
    template <typename ObjectT>
    class IObjectBuilder : public IBuilder<ObjectT*> {
    private:
        ObjectT* m_obj = nullptr;
    protected:
        /// @brief Create a new object.
        /// @return The newly created object.
        /// @note This will use to create the object, in case it's not created. The default
        /// behaviors will use the default constructor (a.k.a. `new ObjectT`), so you can override
        /// this if needed.
        /// @warning This function was only meant to create object by the GetObject() method. If you
        /// just want to get the object, use GetObject() instead!
        virtual ObjectT* CreateObject();

        /// @brief Destroy the object.
        /// @param obj The object to destroy.
        /// @note This will be use to destroy the object in case it's not built. The default
        /// behaviors will use `delete`, so you can override this if needed.
        /// @warning Don't destroy the result object! The destructor will automatically called this.
        virtual void DestroyObject(ObjectT* obj);

        /// @brief Get the current object, or create a new one if not created (for lazy load).
        /// @return The the current or newly created object.
        /// @note Please note that once the object is builded (using Build()), the object builder will
        /// no longer hold the object.
        /// @warning Don't destroy the result object.
        ObjectT* GetObject();
    public:
        IObjectBuilder() = default;
        virtual ~IObjectBuilder();
        
        IObjectBuilder(const IObjectBuilder<ObjectT>&)=delete;
        IObjectBuilder(IObjectBuilder<ObjectT>&&)=delete;
        void operator=(const IObjectBuilder<ObjectT>&)=delete;
        void operator=(IObjectBuilder<ObjectT>&&)=delete;

        /// @brief Build the object.
        /// @note This will return the object pointer, and the builder will no longer hold a references to it.
        /// Instead, if other function called, will create a new object (thus, making memory leak if chaining).
        /// So, it's recommended to warpped the result pointer using smart pointer (e.g. std::shared_ptr),
        /// and this is the last function you call when using a builder.
        ObjectT* Build() override final;
    };
}

template <typename ObjectT>
ObjectT* APE::IObjectBuilder<ObjectT>::CreateObject() {
    return new ObjectT;
}
template <typename ObjectT>
void APE::IObjectBuilder<ObjectT>::DestroyObject(ObjectT* obj) {
    if (obj) delete obj;
}
template <typename ObjectT>
ObjectT* APE::IObjectBuilder<ObjectT>::GetObject() {
    if (!m_obj)
        m_obj = CreateObject();
    return m_obj;
}

template <typename ObjectT>
APE::IObjectBuilder<ObjectT>::~IObjectBuilder() {
    // If referencing (meaning not built), delete the object.
    if (m_obj) delete m_obj;
}

template <typename ObjectT>
ObjectT* APE::IObjectBuilder<ObjectT>::Build() {
    // Get the object, using lazy load. Then 
    ObjectT* result = GetObject();

    // Then un-referencing to the object, and return it.
    m_obj = nullptr;
    return result;
}

#endif // __APE_BUILDER_H__