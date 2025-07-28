#ifndef __APE_STRUCTURE_H__
#define __APE_STRUCTURE_H__

namespace APE {
    class Vector2;
    class Vector3;

    /// @brief The Rectangle Alignment enum, usually for define the alignment in the rectangle.
    enum class RectangleAlignment {
        TopLeft = 0,
        TopCenter = 1,
        TopRight = 2,
        MiddleLeft = 3,
        MiddleCenter = 4,
        MiddleRight = 5,
        BottomLeft = 6,
        BottomCenter = 7,
        BottomRight = 8
    };

    /// @brief The Point struct, represent a pair of two-dimensional integer coordinate (x, y). Usually for screen coordinate.
    struct Point {
    public:
        /// @brief The x value (position along the x-axis) of the Point.
        int X = 0;
        /// @brief The y value (position along the y-axis) of the Point.
        int Y = 0;

        /// @brief Create a new Point, and set all value to 0.
        Point();
        /// @brief Create a new Point, with x and y are both set to the given value.
        /// @param XY The value of x and y to set.
        Point(int XY);
        /// @brief Create a new Point.
        /// @param X The x value (position along the x-axis) of the Point.
        /// @param Y The y value (position along the y-axis) of the Point.
        Point(int X, int Y);

        /// @brief Create a copy of the given Point.
        /// @param p The Point to copy.
        Point(const Point& p);

        Point& operator=(const Point& p);
        Point& operator=(int xy);

        Point& operator+=(const Point& p);
        Point& operator+=(int xy);
        Point operator+(const Point& p) const;
        Point operator+(int xy) const;
        friend Point operator+(int xy, const Point& p);

        Point& operator-=(const Point& p);
        Point& operator-=(int xy);
        Point operator-(const Point& p) const;
        Point operator-(int xy) const;
        friend Point operator-(int xy, const Point& p);

        Point& operator*=(const Point& p);
        Point& operator*=(int xy);
        Point operator*(const Point& p) const;
        Point operator*(int xy) const;
        friend Point operator*(int xy, const Point& p);

        bool operator==(const Point& p) const;
        bool operator==(int xy) const;
        friend bool operator==(int xy, const Point& p);

        bool operator!=(const Point& p) const;
        bool operator!=(int xy) const;
        friend bool operator!=(int xy, const Point& p);

        /// @brief Calculate the distance between the two given Point.
        /// @param a The first Point (the starting Point).
        /// @param b The second Point (the ending Point).
        /// @return The distance between the two given Point.
        static double Distance(const Point& a, const Point& b);

        /// @brief The Zero Point, x and y value are 0 (0, 0)
        static const Point Zero;
        /// @brief The One Point, x and y value are 1 (1, 1)
        static const Point One;
        /// @brief The Up Point, x is 0 and y is 1 (0, 1) 
        static const Point Up;
        /// @brief The Down Point, x is 0 and y is -1 (0, -1) 
        static const Point Down;
        /// @brief The Left Point, x is -1 and y is 0 (-1, 0) 
        static const Point Left;
        /// @brief The Right Point, x is 1 and y is 0 (1, 0) 
        static const Point Right;
    };

    /// @brief The Size struct, represent the size of a two-dimensional integer rectangle. Usually for screen coordinate.
    struct Size {
    public:
        /// @brief The width of the Size (along the x-axis).
        int Width = 0;
        /// @brief The height of the Size (along the y-axis).
        int Height = 0;

        /// @brief Create a new Size, and set all value to 0.
        Size();
        /// @brief Create a new Size, with width and height are both set to the given value.
        /// @param WH The value of width and height to set.
        Size(int WH);
        /// @brief Create a new Size.
        /// @param Width The width of the Size (along the x-axis).
        /// @param Height The height of the Size (along the y-axis).
        Size(int Width, int Height);
        /// @brief Create a new Size, with width and height value are the x and y of the given Point.
        /// @param p The Point to create.
        Size(const Point& p);

        /// @brief Create a copy of the given Size.
        /// @param p The Size to copy.
        Size(const Size& p);

        operator Point() const;

        Size& operator=(const Size& s);
        Size& operator=(int wh);

        Size& operator+=(const Size& s);
        Size& operator+=(int wh);
        Size operator+(const Size& s) const;
        Size operator+(int wh) const;
        friend Size operator+(int wh, const Size& s);

        Size& operator-=(const Size& s);
        Size& operator-=(int wh);
        Size operator-(const Size& s) const;
        Size operator-(int wh) const;
        friend Size operator-(int wh, const Size& s);

        Size& operator*=(const Size& s);
        Size& operator*=(int wh);
        Size operator*(const Size& s) const;
        Size operator*(int wh) const;
        friend Size operator*(int wh, const Size& s);

        bool operator==(const Size& s) const;
        bool operator==(int wh) const;
        friend bool operator==(int wh, const Size& s);

        bool operator!=(const Size& s) const;
        bool operator!=(int wh) const;
        friend bool operator!=(int wh, const Size& s);

        /// @brief Create a new Size with the width and height value are the absolute value of this Size width and height.
        /// @return The absolute Size of this Size.
        Size Absolute() const;

        /// @brief Calculate the ratio (width / height) of the Size.
        /// @return The ratio (width / height) of the Size.
        double Ratio() const;
    
        /// @brief Check if the area of the Size represent is 0.
        /// @return true if the Size area is empty, false otherwise.
        bool IsEmptyArea() const;

        /// @brief Calculate the area that the Size represent.
        /// @return The area of the Size.
        long long Area() const;

        /// @brief Create a new Size with the given ratio (width / height).
        /// @param Ratio The ratio of the size (width / height) to create.
        /// @param Height The height of the size (along the y-axis).
        /// @return The newly created Size.
        static Size FromRatio(double Ratio, int Height);
        
        /// @brief Create a new Size with the given ratio (width / height) and width.
        /// @param Ratio The ratio of the size (width / height) to create.
        /// @param Width The width of the size (along the x-axis).
        /// @return The newly created Size.
        static Size FromRatioWithWidth(double Ratio, int Width);

        /// @brief The Zero Size, width and height value are 0 (0, 0)
        static const Size Zero;
        /// @brief The One Size, width and height value are 1 (1, 1)
        static const Size One;
        /// @brief The Up Size, width is 0 and height is 1 (0, 1) 
        static const Size Up;
        /// @brief The Down Size, width is 0 and height is -1 (0, -1) 
        static const Size Down;
        /// @brief The Left Size, width is -1 and height is 0 (-1, 0) 
        static const Size Left;
        /// @brief The Right Size, width is 1 and height is 0 (1, 0) 
        static const Size Right;
    };


    /// @brief The Rectangle struct, represent a two-dimensional integer rectangle. Usually for screen coordinate.
    struct Rectangle {
    public:
        /// @brief The x position of the Rectangle (usually top-left) corner.
        int X = 0;
        /// @brief The y position of the Rectangle (usually top-left) corner.
        int Y = 0;
        /// @brief The width of the Rectangle (along the x direction).
        int Width = 0;
        /// @brief The height of the Rectangle (along the y direction).
        int Height = 0;

        /// @brief Create a new empty Rectangle.
        Rectangle();
        /// @brief Create a new Rectangle.
        /// @param p The position of the Rectangle (usually top-left) corner.
        /// @param s The size of the Rectangle.
        Rectangle(const Point& p, const Size& s);
        /// @brief Create a new Rectangle.
        /// @param x The x position of the Rectangle (usually top-left) corner.
        /// @param y The y position of the Rectangle (usually top-left) corner.
        /// @param w The width of the Rectangle (along the x direction).
        /// @param h The height of the Rectangle (along the y direction).
        Rectangle(int x, int y, int w, int h);

        Rectangle(const Rectangle& r);

        operator Point() const;
        operator Size() const;

        Rectangle& operator=(const Rectangle& r);

        /// @brief Get a top-left Rectangle that identical to this Rectangle.
        /// @return A top-left Rectangle that identical to this Rectangle.
        Rectangle TopLeftRectangle() const;

        /// @brief Check if this Rectangle is a top-left Rectangle.
        /// @return true if this Rectangle is a top-left Rectangle, false otherwise.
        bool IsTopLeftRectangle() const;
        /// @brief Check if this Rectangle is a top-right Rectangle.
        /// @return true if this Rectangle is a top-right Rectangle, false otherwise.
        bool IsTopRightRectangle() const;
        /// @brief Check if this Rectangle is a bottom-left Rectangle.
        /// @return true if this Rectangle is a bottom-left Rectangle, false otherwise.
        bool IsBottomLeftRectangle() const;
        /// @brief Check if this Rectangle is a bottom-right Rectangle.
        /// @return true if this Rectangle is a bottom-right Rectangle, false otherwise.
        bool IsBottomRightRectangle() const;

        /// @brief Check if the area of the Rectangle is 0.
        /// @return true if the area of the Rectangle is empty, false otherwise.
        bool IsEmptyArea() const;
        /// @brief Calculate the area of the Rectangle.
        /// @return The area of the Rectangle.
        long long Area() const;

        /// @brief Set the position of the Rectangle (usually top-left) corner.
        /// @param p The position to set.
        void SetPosition(const Point& p);
        /// @brief Get the position of the Rectangle (usually top-left) corner.
        /// @return The position of the Rectangle.
        Point GetPosition() const;

        /// @brief Set the size of the Rectangle.
        /// @param s The size to set.
        void SetSize(const Size& s);
        /// @brief Get the size of the Rectangle.
        /// @return The size of the Rectangle.
        Size GetSize() const;
        /// @brief Get the absolute size of the Rectangle (similar to GetSize().Absolute()).
        /// @return The absolute size of the Rectangle.
        Size GetAbsoluteSize() const;

        /// @brief Get the position (along the x direction) of the left side of the Rectangle.
        /// @return The position of the left side of the Rectangle.
        int LeftSide() const;
        /// @brief Get the position (along the x direction) of the right side of the Rectangle.
        /// @return The position of the right side of the Rectangle.
        int RightSide() const;
        /// @brief Get the position (along the x direction) of the center between the left and right the Rectangle.
        /// @return The position of the center between left and right side of the Rectangle.
        int CenterSide() const;
        /// @brief Get the position (along the y direction) of the top side of the Rectangle.
        /// @return The position of the top side of the Rectangle.
        int TopSide() const;
        /// @brief Get the position (along the y direction) of the bottom side of the Rectangle.
        /// @return The position of the bottom side of the Rectangle.
        int BottomSide() const;
        /// @brief Get the position (along the y direction) of the middle between the top and bottom the Rectangle.
        /// @return The position of the middle between top and bottom side of the Rectangle.
        int MiddleSide() const;

        /// @brief Get the top-left corner position of the Rectangle.
        /// @return The top-left position of the Rectangle.
        Point TopLeft() const;
        /// @brief Get the top-center position of the Rectangle.
        /// @return The top-center position of the Rectangle.
        Point TopCenter() const;
        /// @brief Get the top-right corner position of the Rectangle.
        /// @return The top-right position of the Rectangle.
        Point TopRight() const;
        /// @brief Get the middle-left position of the Rectangle.
        /// @return The middle-left position of the Rectangle.
        Point MiddleLeft() const;
        /// @brief Get the middle-center position of the Rectangle.
        /// @return The middle-center position of the Rectangle.
        Point MiddleCenter() const;
        /// @brief Get the middle-right position of the Rectangle.
        /// @return The middle-right position of the Rectangle.
        Point MiddleRight() const;
        /// @brief Get the bottom-left corner position of the Rectangle.
        /// @return The bottom-left position of the Rectangle.
        Point BottomLeft() const;
        /// @brief Get the bottom-center position of the Rectangle.
        /// @return The bottom-center position of the Rectangle.
        Point BottomCenter() const;
        /// @brief Get the bottom-right corner position of the Rectangle.
        /// @return The bottom-right position of the Rectangle.
        Point BottomRight() const;

        /// @brief Check if the Rectangle is contain the given Point.
        /// @param p The Point to check.
        /// @return true if the Rectangle is contain the given Point, false otherwise.
        bool IsContain(const Point& p) const;
        /// @brief Check if the Rectangle is contain the given Rectangle.
        /// @param r The Rectangle to check.
        /// @return true if this Rectangle is contain the given Rectangle, false otherwise.
        bool IsContain(const Rectangle& r) const;

        /// @brief Calculate the smallest Rectangle that contain this Rectangle and the given Point.
        /// @param p The Point to calculate.
        /// @return The smallest Rectangle that contain both this Rectangle and the given Point.
        Rectangle UnionWith(const Point& p) const;
        /// @brief Calculate the smallest Rectangle that contain this Rectangle and the given Rectangle.
        /// @param p The other Rectangle to calculate.
        /// @return The smallest Rectangle that contain both this and the given Rectangle.
        Rectangle UnionWith(const Rectangle& r) const;

        /// @brief Calculate the global position of a local position that related to this Rectangle.
        /// @param LocalPosition The local position to calculate. (0, 0) mean the Rectangle top-left corner.
        /// @return The global position of the given local position that related to this Rectangle.
        Point LocalToGlobal(const Point& LocalPosition) const;
        /// @brief Calculate the global rectangle of a local rectangle that related to this Rectangle.
        /// @param LocalRectangle The local rectangle to calculate.
        /// @param Alignment The alignment that the given Rectangle is related to this Rectangle. Default is TopLeft.
        /// @return The global rectangle of the given local rectangle that related to this Rectangle.
        Rectangle LocalToGlobal(const Rectangle& LocalRectangle, RectangleAlignment Alignment = RectangleAlignment::TopLeft) const;

        /// @brief Calculate the local position that related to this Rectangle from a global position.
        /// @param GlobalPosition The global position to calculate.
        /// @return The local position that related to this Rectangle ((0, 0) mean the Rectangle top-left corner)
        /// of the given global position.
        Point GlobalToLocal(const Point& GlobalPosition) const;

        /// @brief Calculate the smallest Rectangle that contain the two given Point.
        /// @param a The first Point.
        /// @param b The second Point.
        /// @return The result Rectangle.
        static Rectangle FromTwoPoint(const Point& a, const Point& b);

        /// @brief Calculate the intersection of the given two Rectangle.
        /// @param r1 The first Rectangle.
        /// @param r2 The second Rectangle.
        /// @return The Rectangle represent the intersection, or an empty Rectangle if there're no intersection.
        static Rectangle Intersect(const Rectangle& r1, const Rectangle& r2);

        /// @brief Calculate the smallest Rectangle that contain the two given Rectangle and Point.
        /// @param r The given Rectangle to calculate.
        /// @param p The given Point to calculate.
        /// @return The smallest Rectangle that contain the two given Rectangle and Point.
        static Rectangle Union(const Rectangle& r, const Point& p);

        /// @brief Calculate the smallest Rectangle that contain the two given Rectangle.
        /// @param r1 The first Rectangle.
        /// @param r2 The second Rectangle.
        /// @return The smallest Rectangle that contain the two given Rectangle.
        static Rectangle Union(const Rectangle& r1, const Rectangle& r2);

        /// @brief The empty Rectangle with all value are 0.
        static const Rectangle Empty;
    };
    
    /// @brief The Vector2 class, represents a 2D vector.
    class Vector2 final {
    public:
        /// @brief The X component of the Vector2.
        double X = 0;
        /// @brief The Y component of the Vector2.
        double Y = 0;

        /// @brief Default constructor. Initializes x and y to 0.
        Vector2() = default;
        /// @brief Construct a Vector2 with given x and y.
        /// @param x X component
        /// @param y Y component
        Vector2(double x, double y);

        Vector2 operator+(const Vector2& right) const;
        Vector2& operator+=(const Vector2& right);
        
        Vector2 operator-(const Vector2& right) const;
        Vector2& operator-=(const Vector2& right);
        
        Vector2 operator*(double scalar) const;
        Vector2& operator*=(double scalar);
        Vector3 operator*(const Vector2& right) const;

        Vector2& operator=(const Vector2& right);

        bool operator==(const Vector2& right) const;
        bool operator!=(const Vector2& right) const;

        /// @brief Computes the dot product of two Vector2s.
        static double DotProduct(const Vector2& left, const Vector2& right);

        /// @brief Constant vector (0, 0)
        static const Vector2 Zero;
        /// @brief Constant vector (1, 1)
        static const Vector2 One;
        /// @brief Constant vector (-1, 0) (left direction)
        static const Vector2 Left;
        /// @brief Constant vector (1, 0) (right direction)
        static const Vector2 Right;
        /// @brief Constant vector (0, 1) (up direction)
        static const Vector2 Up;
        /// @brief Constant vector (0, -1) (down direction)
        static const Vector2 Down;
    };

    /// @brief The Vector3 class, represents a 3D vector.
    class Vector3 final {
    public:
        /// @brief The X component of the Vector2.
        double X = 0;
        /// @brief The Y component of the Vector2.
        double Y = 0;
        /// @brief The Y component of the Vector2.
        double Z = 0;

        /// @brief Default constructor. Initializes x, y, z to 0.
        Vector3();
        /// @brief Construct a Vector3 with given x, y, z.
        /// @param x X component
        /// @param y Y component
        /// @param z Z component
        Vector3(double x, double y, double z);
        /// @brief Construct a Vector3 from a Vector2 and z value.
        /// @param v2 2D vector
        /// @param z Z component (default 0.0)
        Vector3(const Vector2& v2, double z = 0.0);

        operator Vector2() const;

        Vector3 operator+(const Vector3& right) const;
        Vector3& operator+=(const Vector3& right);

        Vector3 operator-(const Vector3& right) const;
        Vector3& operator-=(const Vector3& right);
        
        Vector3 operator*(double scalar) const;
        Vector3 operator*(const Vector3& right) const;
        Vector3& operator*=(double scalar);
        Vector3& operator*=(const Vector3& right);

        Vector3& operator=(const Vector3& right);

        bool operator==(const Vector3& right) const;
        bool operator!=(const Vector3& right) const;

        /// @brief Computes the dot product of two Vector3s.
        static double DotProduct(const Vector3& left, const Vector3& right);

        /// @brief Constant vector (0, 0, 0)
        static const Vector3 Zero;
        /// @brief Constant vector (1, 1, 1)
        static const Vector3 One;
        /// @brief Constant vector (-1, 0, 0) (left direction)
        static const Vector3 Left;
        /// @brief Constant vector (1, 0, 0) (right direction)
        static const Vector3 Right;
        /// @brief Constant vector (0, 1, 0) (up direction)
        static const Vector3 Up;
        /// @brief Constant vector (0, -1, 0) (down direction)
        static const Vector3 Down;
        /// @brief Constant vector (0, 0, 1) (forward direction)
        static const Vector3 Forward;
        /// @brief Constant vector (0, 0, -1) (backward direction)
        static const Vector3 Backward;
    };

}

#endif // __APE_STRUCTURE_H__