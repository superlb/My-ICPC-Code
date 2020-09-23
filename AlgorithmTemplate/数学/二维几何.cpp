const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1010;
int sgn(double x)
{
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    else return 1;
}
inline double sqr(double x){return x*x;}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x=_x;y=_y;
    }
    bool operator == (Point b) const
    {
        return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
    }
    bool operator < (Point b) const
    {
        return sgn(x-b.x) == 0 ? sgn(y-b.y) == 0 : x<b.x;
    }
    Point operator + (const Point &b) const
    {
        return Point(x+b.x,y+b.y);
    }
    Point operator - (const Point &b) const
    {
        return Point(x-b.x,y-b.y);
    }
    Point operator * (const double &k) const
    {
        return Point(x*k,y*k);
    }
    Point operator / (const double &k) const
    {
        return Point(x/k,y/k);
    }
    //叉积
    double operator ^ (Point b) const
    {
        return x*b.y-y*b.x;
    }
    //点积
    double operator * (Point b) const
    {
        return x*b.x+y*b.y;
    }
    //返回长度
    double len()
    {
        return hypot(x,y);
    }
    //长度的平方
    double len2()
    {
        return x*x+y*y;
    }
    //返回两点的距离
    double distance(Point p)
    {
        return hypot(x-p.x,y-p.y);
    }
    //计算∠pab
    double rad(Point a,Point b)
    {
        Point p=*this;
        return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
    }
    //化为长度为r的向量
    Point trunc(double r)
    {
        double l = len();
        if(!sgn(l))return *this;
        r /= l;
        return Point(x*r,y*r);
    }
    //逆时针旋转90度
    Point rotleft()
    {
        return Point(-y,x);
    }
    //顺时针旋转90度
    Point rotleft()
    {
        return Point(y,-x);
    }
    //绕着p点逆时针旋转angle
    Point rotate(Point p,double angle)
    {
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x+v.x*c - v.y*s, p.y+v.x*s+v.y*c);
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s=_s;e=_e;
    }
    bool operator == (const Line &v) const
    {
        return (s == v.s) && (e == v.e);
    }
    //点与斜角
    Line(Point p,double angle)
    {
        s=p;
        if(sgn(angle-pi/2) == 0) e=(s+Point(0,1));
        else e=(s+Point(1,tan(angle)));
    }
    Line(double a,double b,double c)
    {
        if(sgn(a) == 0)
        {
            s=Point(0,-c/b);e=Point(1,-c/b);
        }
        else if(sgn(b) == 0)
        {
            s=Point(-c/a,0);e=Point(-c/a,1);
        }
        else
        {
            s=Point(0,-c/b);e=Point(1,(-c-a)/b);
        }
    }
    void adjust()
    {
        if(e<s)swap(s,e);
    }
    double length()
    {
        return s.distance(e);
    }
    double angle()
    {
        double k=atan2(e.y-s.y,e.x-s.x);
        if(sgn(j) < 0) k+=pi;
        if(sgn(k-pi) == 0) k-=pi;
        return k;
    }
    //点和直线关系
    //1在左侧，2在右侧，3在直线上
    int relation(Point p)
    {
        int c=sgn((p-s)^(e-s));
        if(c<0)return 1;
        else if(c>0)return 2;
        else return 3;
    }
    //点在线段上的判断
    bool pointonseg(Point p)
    {
        return sgn((p-s)^(e-s)) == 0 && sgn((p-s)^(p-e)) <= 0;
    }
    //两向量平行
    bool parallel(Line v)
    {
        return sgn((e-s)^(v.e-v.s)) == 0;
    }
    //两线段相交判断
    //2规范相交，1非规范相交，0不相交
    int segcrossseg(Line v)
    {
        int d1=sgn((e-s)^(v.s-s));
        int d2=sgn((e-s)^(v.e-s));
        int d3=sgn((v.e-v.s)^(s-v.s));
        int d4=sgn((v.e-v.s)^(e-v.s));
        if( (d1^d2)==-2 && (d3^d3)==-2 )return 2;
        return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) ||
            (d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
            (d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
            (d4==0 && sgn((e-v.s)*(e-v.e))<=0);
    }
    //直线和线段相交判断
    //2规范相交，1非规范相交，0不相交
    int linecrossseg(Line v)
    {
        int d1=sgn((e-s)^(v.s-s));
        int d2=sgn((e-s)^(v.e-s));
        if((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    //两直线关系
    //0平行，1重合，2相交
    int linecrossline(Line v)
    {
        if((*this).parallel(v))
            return v.relation(s)==3;
        return 2;
    }
    //求两直线的交点
    Point crosspoint(Line v)
    {
        double a1=(v.e-v.s)^(s-v.s);
        double a2=(v.e-v.s)^(e-v.s);
        return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
    }
    //点到直线的距离
    double dispointtoline(Point p)
    {
        return fabs((p-s)^(e-s))/length();
    }
    //点到线段的距离
    double dispointtoseg(Point p)
    {
        if(sgn((p-s)*(e-s))<0 || sgn((p-e)^(s-e))<0)
            return min(p.distance(s),p.distance(e));
        return dispointtoline(p);
    }
    //线段到线段的距离
    double dissegtoseg(Line v)
    {
        return min({dispointtoseg(v.s),dispointtoseg(v.e),v.dispointtoseg(s),v.dispointtoseg(e)});
    }
    //返回点在直线上的投影
    Point lineprog(Point p)
    {
        return s+( ((e-s)*((e-s)*(p-s))) / ((e-s).len2()) );
    }
    //返回点关于直线的对称点
    Point symmetrypoint(Point p)
    {
        Point q = lineprog(p);
        return Point(2*q.x-p.x,2*q.y-p.y);
    }
};
