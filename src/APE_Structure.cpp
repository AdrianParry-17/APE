#include "APE/APE_Structure.h"
#include "APE/APE_Define.h"

#include <math.h>

//* --- APE::Point ---

APE::Point::Point() = default;
APE::Point::Point(int XY) : X(XY), Y(XY) {}
APE::Point::Point(int X, int Y) : X(X), Y(Y) {}

APE::Point::Point(const APE::Point& p) : X(p.X), Y(p.Y) {}

APE::Point& APE::Point::operator=(const APE::Point& p) { X = p.X; Y = p.Y; return *this; }
APE::Point& APE::Point::operator=(int xy) { X = xy; Y = xy; return *this; }

APE::Point& APE::Point::operator+=(const APE::Point& p) { X += p.X; Y += p.Y; return *this; }
APE::Point& APE::Point::operator+=(int xy) { X += xy; Y += xy; return *this; }
APE::Point APE::Point::operator+(const APE::Point& p) const { return {X + p.X, Y + p.Y}; }
APE::Point APE::Point::operator+(int xy) const { return {X + xy, Y + xy}; }
APE::Point operator+(int xy, const APE::Point& p) { return {xy + p.X, xy + p.Y}; }

APE::Point& APE::Point::operator-=(const APE::Point& p) { X -= p.X; Y -= p.Y; return *this; }
APE::Point& APE::Point::operator-=(int xy) { X -= xy; Y -= xy; return *this; }
APE::Point APE::Point::operator-(const APE::Point& p) const { return {X - p.X, Y - p.Y}; }
APE::Point APE::Point::operator-(int xy) const { return {X - xy, Y - xy}; }
APE::Point operator-(int xy, const APE::Point& p) { return {xy - p.X, xy - p.Y}; }

APE::Point& APE::Point::operator*=(const APE::Point& p) { X *= p.X; Y *= p.Y; return *this; }
APE::Point& APE::Point::operator*=(int xy) { X *= xy; Y *= xy; return *this; }
APE::Point APE::Point::operator*(const APE::Point& p) const { return {X * p.X, Y * p.Y}; }
APE::Point APE::Point::operator*(int xy) const { return {X * xy, Y * xy}; }
APE::Point operator*(int xy, const APE::Point& p) { return {xy * p.X, xy * p.Y}; }

bool APE::Point::operator==(const APE::Point& p) const { return X == p.X && Y == p.Y; }
bool APE::Point::operator==(int xy) const { return X == xy && Y == xy; }
bool operator==(int xy, const APE::Point& p) { return xy == p.X && xy == p.Y; }

bool APE::Point::operator!=(const APE::Point& p) const { return X != p.X || Y != p.Y; }
bool APE::Point::operator!=(int xy) const { return X != xy || Y != xy; }
bool operator!=(int xy, const APE::Point& p) { return xy != p.X || xy != p.Y; }

double APE::Point::Distance(const APE::Point& a, const APE::Point& b) { return hypot(b.X - a.X, b.Y - a.Y); }

const APE::Point APE::Point::Zero = APE::Point(0, 0);
const APE::Point APE::Point::One = APE::Point(1, 1);
const APE::Point APE::Point::Up = APE::Point(0, 1);
const APE::Point APE::Point::Down = APE::Point(0, -1);
const APE::Point APE::Point::Left = APE::Point(-1, 0);
const APE::Point APE::Point::Right = APE::Point(1, 0);

//* --- APE::Size ---

APE::Size::Size() = default;
APE::Size::Size(int WH) : Width(WH), Height(WH) {}
APE::Size::Size(int Width, int Height) : Width(Width), Height(Height) {}
APE::Size::Size(const APE::Point& p) : Width(p.X), Height(p.Y) {}
APE::Size::Size(const APE::Size& p) : Width(p.Width), Height(p.Height) {}

APE::Size::operator Point() const { return Point(Width, Height); }

APE::Size& APE::Size::operator=(const Size& s) { Width = s.Width; Height = s.Height; return *this; }
APE::Size& APE::Size::operator=(int wh) { Width = wh; Height = wh; return *this; }

APE::Size& APE::Size::operator+=(const Size& s) { Width += s.Width; Height += s.Height; return *this; }
APE::Size& APE::Size::operator+=(int wh) { Width += wh; Height += wh; return *this; }
APE::Size APE::Size::operator+(const Size& s) const { return {Width + s.Width, Height + s.Height}; }
APE::Size APE::Size::operator+(int wh) const { return {Width + wh, Height + wh}; }
APE::Size operator+(int wh, const APE::Size& s) { return {wh + s.Width, wh + s.Height}; }

APE::Size& APE::Size::operator-=(const Size& s) { Width -= s.Width; Height -= s.Height; return *this; }
APE::Size& APE::Size::operator-=(int wh) { Width -= wh; Height -= wh; return *this; }
APE::Size APE::Size::operator-(const Size& s) const { return {Width - s.Width, Height - s.Height}; }
APE::Size APE::Size::operator-(int wh) const { return {Width - wh, Height - wh}; }
APE::Size operator-(int wh, const APE::Size& s) { return {wh - s.Width, wh - s.Height}; }

APE::Size& APE::Size::operator*=(const Size& s) { Width *= s.Width; Height *= s.Height; return *this; }
APE::Size& APE::Size::operator*=(int wh) { Width *= wh; Height *= wh; return *this; }
APE::Size APE::Size::operator*(const Size& s) const { return {Width * s.Width, Height * s.Height}; }
APE::Size APE::Size::operator*(int wh) const { return {Width * wh, Height * wh}; }
APE::Size operator*(int wh, const APE::Size& s) { return {wh * s.Width, wh * s.Height}; }

bool APE::Size::operator==(const Size& s) const { return Width == s.Width && Height == s.Height; }
bool APE::Size::operator==(int wh) const { return Width == wh && Height == wh; }
bool operator==(int wh, const APE::Size& s) { return wh == s.Width && wh == s.Height; }

bool APE::Size::operator!=(const Size& s) const { return Width != s.Width || Height != s.Height; }
bool APE::Size::operator!=(int wh) const { return Width != wh || Height != wh; }
bool operator!=(int wh, const APE::Size& s) { return wh != s.Width || wh != s.Height; }

APE::Size APE::Size::Absolute() const { return Size(abs(Width), abs(Height)); }
double APE::Size::Ratio() const { return fabs(Width) / fabs(Height); }
bool APE::Size::IsEmptyArea() const { return Width == 0 || Height == 0; }
long long APE::Size::Area() const { return llabs(Width) * llabs(Height); }

APE::Size APE::Size::FromRatio(double Ratio, int Height) { return Size((int)abs(Ratio * Height), abs(Height)); }
APE::Size APE::Size::FromRatioWithWidth(double Ratio, int Width) { return Size(abs(Width), (int)abs((double)Width / Ratio)); }

const APE::Size APE::Size::Zero = APE::Size(0, 0);
const APE::Size APE::Size::One = APE::Size(1, 1);
const APE::Size APE::Size::Up = APE::Size(0, 1);
const APE::Size APE::Size::Down = APE::Size(0, -1);
const APE::Size APE::Size::Left = APE::Size(-1, 0);
const APE::Size APE::Size::Right = APE::Size(1, 0);

//* --- APE::Rectangle ---

APE::Rectangle::Rectangle() = default;
APE::Rectangle::Rectangle(const APE::Point& p, const APE::Size& s) : X(p.X), Y(p.Y), Width(s.Width), Height(s.Height) {}
APE::Rectangle::Rectangle(int x, int y, int w, int h) : X(x), Y(y), Width(w), Height(h) {}
APE::Rectangle::Rectangle(const APE::Rectangle& r) : X(r.X), Y(r.Y), Width(r.Width), Height(r.Height) {}

APE::Rectangle::operator Point() const { return {X, Y}; }
APE::Rectangle::operator Size() const { return {Width, Height}; }

APE::Rectangle& APE::Rectangle::operator=(const Rectangle& r) { X = r.X; Y = r.Y; Width = r.Width; Height = r.Height; return *this; }

APE::Rectangle APE::Rectangle::TopLeftRectangle() const { return {LeftSide(), RightSide(), abs(Width), abs(Height)}; }

bool APE::Rectangle::IsTopLeftRectangle() const { return Width >= 0 && Height >= 0; }
bool APE::Rectangle::IsTopRightRectangle() const { return Width < 0 && Height >= 0; }
bool APE::Rectangle::IsBottomLeftRectangle() const { return Width >= 0 && Height < 0; }
bool APE::Rectangle::IsBottomRightRectangle() const { return Width < 0 && Height < 0; }

bool APE::Rectangle::IsEmptyArea() const { return Width == 0 || Height == 0; }
long long APE::Rectangle::Area() const { return llabs(Width) * llabs(Height); }

void APE::Rectangle::SetPosition(const Point& p) { X = p.X; Y = p.Y; }
APE::Point APE::Rectangle::GetPosition() const { return {X, Y}; }
void APE::Rectangle::SetSize(const Size& s) { Width = s.Width; Height = s.Height; }
APE::Size APE::Rectangle::GetSize() const { return {Width, Height}; }
APE::Size APE::Rectangle::GetAbsoluteSize() const { return {abs(Width), abs(Height)}; }

int APE::Rectangle::LeftSide() const { return Width < 0 ? X + Width + 1 : X; }
int APE::Rectangle::RightSide() const { return Width > 0 ? X + Width - 1 : X; }
int APE::Rectangle::CenterSide() const { return X + (Width / 2); }
int APE::Rectangle::TopSide() const { return Height < 0 ? Y + Height + 1 : Y; }
int APE::Rectangle::BottomSide() const { return Height > 0 ? Y + Height - 1 : Y; }
int APE::Rectangle::MiddleSide() const { return X + (Height / 2); }

APE::Point APE::Rectangle::TopLeft() const { return {LeftSide(), TopSide()}; }
APE::Point APE::Rectangle::TopCenter() const { return {CenterSide(), TopSide()}; }
APE::Point APE::Rectangle::TopRight() const { return {RightSide(), TopSide()}; }
APE::Point APE::Rectangle::MiddleLeft() const { return {LeftSide(), MiddleSide()}; }
APE::Point APE::Rectangle::MiddleCenter() const { return {CenterSide(), MiddleSide()}; }
APE::Point APE::Rectangle::MiddleRight() const { return {RightSide(), MiddleSide()}; }
APE::Point APE::Rectangle::BottomLeft() const { return {LeftSide(), BottomSide()}; }
APE::Point APE::Rectangle::BottomCenter() const { return {CenterSide(), BottomSide()}; }
APE::Point APE::Rectangle::BottomRight() const { return {RightSide(), BottomSide()}; }

bool APE::Rectangle::IsContain(const APE::Point& p) const {
    return p.X >= LeftSide() && p.X <= RightSide() && p.Y >= TopSide() && p.Y <= BottomSide();
}
bool APE::Rectangle::IsContain(const APE::Rectangle& r) const {
    int left = LeftSide(), right = RightSide(), top = TopSide(), bottom = BottomSide();
    Point tl = r.TopLeft(), br = r.BottomRight();
    return tl.X >= left && tl.X <= right && tl.Y >= top && tl.Y <= bottom   // Top-Left check
        && br.X >= left && br.X <= right && br.Y >= top && br.Y <= bottom;  // Bottom-Right check
}

APE::Rectangle APE::Rectangle::UnionWith(const Point& p) const { return Union(*this, p); }
APE::Rectangle APE::Rectangle::UnionWith(const Rectangle& r) const { return Union(*this, r); }

APE::Point APE::Rectangle::LocalToGlobal(const Point& LocalPosition) const { return Point(LocalPosition.X + LeftSide(), LocalPosition.Y + TopSide()); }
APE::Rectangle APE::Rectangle::LocalToGlobal(const Rectangle& LocalRectangle, APE::RectangleAlignment Alignment) const {
    switch (Alignment)
    {
    case RectangleAlignment::TopCenter:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide() + ((abs(Width) - abs(LocalRectangle.Width)) / 2),
            TopSide() + LocalRectangle.TopSide(),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    case RectangleAlignment::TopRight:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide() + (abs(Width) - abs(LocalRectangle.Width)),
            TopSide() + LocalRectangle.TopSide(),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    case RectangleAlignment::MiddleLeft:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide(),
            TopSide() + LocalRectangle.TopSide() + ((abs(Height) - abs(LocalRectangle.Height)) / 2),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    case RectangleAlignment::MiddleCenter:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide() + ((abs(Width) - abs(LocalRectangle.Width)) / 2),
            TopSide() + LocalRectangle.TopSide() + ((abs(Height) - abs(LocalRectangle.Height)) / 2),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    case RectangleAlignment::MiddleRight:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide() + (abs(Width) - abs(LocalRectangle.Width)),
            TopSide() + LocalRectangle.TopSide() + ((abs(Height) - abs(LocalRectangle.Height)) / 2),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    case RectangleAlignment::BottomLeft:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide(),
            TopSide() + LocalRectangle.TopSide() + (abs(Height) - abs(LocalRectangle.Height)),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    case RectangleAlignment::BottomCenter:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide() + ((abs(Width) - abs(LocalRectangle.Width)) / 2),
            TopSide() + LocalRectangle.TopSide() + (abs(Height) - abs(LocalRectangle.Height)),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    case RectangleAlignment::BottomRight:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide() + (abs(Width) - abs(LocalRectangle.Width)),
            TopSide() + LocalRectangle.TopSide() + (abs(Height) - abs(LocalRectangle.Height)),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    default:
        return Rectangle(
            LeftSide() + LocalRectangle.LeftSide(),
            TopSide() + LocalRectangle.TopSide(),
            abs(LocalRectangle.Width), abs(LocalRectangle.Height));
    }
}

APE::Point APE::Rectangle::GlobalToLocal(const APE::Point& GlobalPosition) const { return APE::Point(GlobalPosition.X - LeftSide(), GlobalPosition.Y - TopSide()); }
APE::Rectangle APE::Rectangle::FromTwoPoint(const Point& a, const Point& b) {
    return {APE_MIN(a.X, b.X), APE_MIN(a.Y, b.Y), abs(b.X - a.X) + 1, abs(b.Y - a.Y) + 1};
}
APE::Rectangle APE::Rectangle::Intersect(const APE::Rectangle& r1, const APE::Rectangle& r2) {
    if (r1.IsEmptyArea() || r2.IsEmptyArea())
        return Rectangle::Empty;
    Point tl1 = r1.TopLeft(), tl2 = r2.TopLeft(), br1 = r1.BottomRight(), br2 = r2.BottomRight();
    int left = APE_MAX(tl1.X, tl2.X), top = APE_MAX(tl1.Y, tl2.Y), right = APE_MIN(br1.X, br2.X), bottom = APE_MIN(br1.Y, br2.Y);
    if (right < left || bottom < top) return Rectangle::Empty;
    return {left, top, right - left + 1, bottom - top + 1};
}
APE::Rectangle APE::Rectangle::Union(const APE::Rectangle& r, const APE::Point& p) {
    if (r.IsEmptyArea())
        return FromTwoPoint(r.GetPosition(), p);
    int left = r.LeftSide(), top = r.TopSide(), right = r.RightSide(), bottom = r.BottomSide();
    int x = APE_MIN(left, p.X), y = APE_MIN(top, p.Y);
    return {x, y, APE_MAX(right, p.X) - x + 1,  APE_MAX(bottom, p.Y) - y + 1};
}
APE::Rectangle APE::Rectangle::Union(const APE::Rectangle& r1, const APE::Rectangle& r2) {
    if (r1.IsEmptyArea())
        return Union(r2, r1.GetPosition());
    if (r2.IsEmptyArea())
        return Union(r1, r2.GetPosition());
    int left1 = r1.LeftSide(), top1 = r1.TopSide(), right1 = r1.RightSide(), bottom1 = r1.BottomSide();
    int left2 = r2.LeftSide(), top2 = r2.TopSide(), right2 = r2.RightSide(), bottom2 = r2.BottomSide();
    int x = APE_MIN(left1, left2), y = APE_MIN(top1, top2);
    return {x, y, APE_MAX(right1, right2) - x + 1, APE_MAX(bottom1, bottom2) - y + 1};
}

const APE::Rectangle APE::Rectangle::Empty = APE::Rectangle(0, 0, 0, 0);

//* ---- Vector2 ----

APE::Vector2::Vector2(double x, double y) : X(x), Y(y) {}
APE::Vector2& APE::Vector2::operator=(const Vector2& right) { X = right.X; Y = right.Y; return *this; }

APE::Vector2& APE::Vector2::operator+=(const Vector2& right) { X += right.X; Y += right.Y; return *this; }
APE::Vector2 APE::Vector2::operator+(const Vector2& right) const {
    return Vector2(X + right.X, Y + right.Y);
}
APE::Vector2& APE::Vector2::operator-=(const Vector2& right) { X -= right.X; Y -= right.Y; return *this; }
APE::Vector2 APE::Vector2::operator-(const Vector2& right) const {
    return Vector2(X - right.X, Y - right.Y);
}

APE::Vector2& APE::Vector2::operator*=(double scalar) { X *= scalar; Y *= scalar; return *this; }
APE::Vector2 APE::Vector2::operator*(double scalar) const {
    return Vector2(X * scalar, Y * scalar);
}

APE::Vector3 APE::Vector2::operator*(const Vector2& right) const {
    return Vector3(0, 0, X * right.Y - Y * right.X);
}

double APE::Vector2::DotProduct(const Vector2& left, const Vector2& right) {
    return left.X * right.X + left.Y * right.Y;
}
bool APE::Vector2::operator==(const Vector2& right) const {
    return X == right.X && Y == right.Y;
}
bool APE::Vector2::operator!=(const Vector2& right) const {
    return !(*this == right);
}

// ---- Vector2 constants ----
const APE::Vector2 APE::Vector2::Zero     = APE::Vector2(0.0, 0.0);
const APE::Vector2 APE::Vector2::One      = APE::Vector2(1.0, 1.0);
const APE::Vector2 APE::Vector2::Left     = APE::Vector2(-1.0, 0.0);
const APE::Vector2 APE::Vector2::Right    = APE::Vector2(1.0, 0.0);
const APE::Vector2 APE::Vector2::Up       = APE::Vector2(0.0, 1.0);
const APE::Vector2 APE::Vector2::Down     = APE::Vector2(0.0, -1.0);

//* ---- Vector3 ----

APE::Vector3::Vector3() : X(0), Y(0), Z(0) {}
APE::Vector3::Vector3(double x, double y, double z) : X(x), Y(y), Z(z) {}
APE::Vector3::Vector3(const Vector2& v2, double z) : X(v2.X), Y(v2.Y), Z(z) {}

APE::Vector3& APE::Vector3::operator=(const Vector3& right) { X = right.X; Y = right.Y; Z = right.Z; return *this; }

APE::Vector3& APE::Vector3::operator+=(const Vector3& right) { X += right.X; Y += right.Y; Z += right.Z; return *this; }
APE::Vector3 APE::Vector3::operator+(const Vector3& right) const {
    return Vector3(X + right.X, Y + right.Y, Z + right.Z);
}

APE::Vector3& APE::Vector3::operator-=(const Vector3& right) { X -= right.X; Y -= right.Y; Z -= right.Z; return *this; }
APE::Vector3 APE::Vector3::operator-(const Vector3& right) const {
    return Vector3(X - right.X, Y - right.Y, Z - right.Z);
}

APE::Vector3& APE::Vector3::operator*=(double scalar) { X *= scalar; Y *= scalar; Z *= scalar; return *this; }
APE::Vector3 APE::Vector3::operator*(double scalar) const {
    return APE::Vector3(X * scalar, Y * scalar, Z * scalar);
}
APE::Vector3& APE::Vector3::operator*=(const Vector3& right) {
    double tmp_x = 0, tmp_y = 0, tmp_z = 0;
    tmp_x = Y * right.Z - Z * right.Y;
    tmp_y = Z * right.X - X * right.Z;
    tmp_z = X * right.Y - Y * right.X;
    X = tmp_x; Y = tmp_y; Z = tmp_z;
    return *this;
}
APE::Vector3 APE::Vector3::operator*(const Vector3& right) const {
    return Vector3(
        Y * right.Z - Z * right.Y,
        Z * right.X - X * right.Z,
        X * right.Y - Y * right.X
    );
}

double APE::Vector3::DotProduct(const Vector3& left, const Vector3& right) {
    return left.X * right.X + left.Y * right.Y + left.Z * right.Z;
}

bool APE::Vector3::operator==(const Vector3& right) const {
    return X == right.X && Y == right.Y && Z == right.Z;
}
bool APE::Vector3::operator!=(const Vector3& right) const {
    return !(*this == right);
}
APE::Vector3::operator Vector2() const { return Vector2(X, Y); }

// ---- Vector3 constants ----
const APE::Vector3 APE::Vector3::Zero      = APE::Vector3(0.0, 0.0, 0.0);
const APE::Vector3 APE::Vector3::One       = APE::Vector3(1.0, 1.0, 1.0);
const APE::Vector3 APE::Vector3::Left      = APE::Vector3(-1.0, 0.0, 0.0);
const APE::Vector3 APE::Vector3::Right     = APE::Vector3(1.0, 0.0, 0.0);
const APE::Vector3 APE::Vector3::Up        = APE::Vector3(0.0, 1.0, 0.0);
const APE::Vector3 APE::Vector3::Down      = APE::Vector3(0.0, -1.0, 0.0);
const APE::Vector3 APE::Vector3::Forward   = APE::Vector3(0.0, 0.0, 1.0);
const APE::Vector3 APE::Vector3::Backward  = APE::Vector3(0.0, 0.0, -1.0);