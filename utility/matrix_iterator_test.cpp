//
//// $Id: yasli_fill_iterator.h 754 2006-10-17 19:59:11Z syntheticpp $
//
//
//#include <iostream>
//#include <iterator>
//#include <cstddef>
//#include <utility>
//
//
//namespace my_nstd
//{
//	typedef std::pair<int,int> Point;
//	std::pair<int,int> down(1,0);
//	std::pair<int,int> right(0,1);
//	std::pair<int,int> upright(-1,1);
//	std::pair<int,int> downleft(1,-1);
//	enum{Left, Top, Right, Bottom, RightBottom,Normal, End};
//
//	template <int tX, int tY, int bX, int bY>
//    class fill_iterator
//    {
//        /*difference_type*/ ptrdiff_t x_;//////////////////////////////////
//        /*difference_type*/ ptrdiff_t y_;//////////////////////////////////
//		Point step_;
//		int state_;
//		void forward_step( )
//		{
//			if (state_ == Normal)
//			{
//				state_ = position(x_+step_.first, y_+step_.second);
//			}
//			else if (position() == RightBottom)
//			{
//				state_ = End;
//				step_ = right;
//			}
//			else if ( (state_ == Bottom|| state_ == Left)&& position() == Bottom)
//			{
//				step_ = right;
//				state_ = Normal;
//			}
//			else if (position() == Bottom&& state_ == Normal)
//			{
//				step_ == upright;
//			}
//			else if(position() == Right && (state_ == Right|| state_ == Top))
//			{
//				step_ = down;
//				state_ = Normal;
//			}
//			else if (position() == Right&& state_ == Normal)
//			{
//				step_ = downleft;
//			}
//			else if (position() == Left && state_ == Left)
//			{
//				step_ = down;
//				state_ = Normal;
//			}
//			else if (position() == Left&& state_ == Normal)
//			{
//				step_ = upright;
//			}
//			else if (position() == Top && state_ == Top)
//			{
//				step_ = right;
//				state_ = Normal;
//			}
//			else if (position() == Top && state_ == Normal)
//			{
//				step_ = downleft;
//				state_ = Normal;
//			}
//			
//
//			x_ += step_.first;
//			y_ += step_.second;
//
//		}
//		int position()
//		{
//			return position(x_, y_);
//		}
//		
//	
//
//    
//    public:
//		fill_iterator():state_(Left), x_(0),y_(0){}
//		fill_iterator(int):state_(Left), x_(bX-1),y_(bY){}
//
//        int operator*() const
//        {
//            return (bY - tY)* x_ + y_ ;
//        }
//		int get_x()const
//		{
//			return x_;
//		}
//
//		int get_y()const
//		{
//			return y_;
//		}
//
//        fill_iterator& operator++()
//        {    
//            forward_step();
//            return *this;
//        }
//
//        fill_iterator operator++(int)
//        {
//            fill_iterator it(*this);
//            ++*this;
//            return it;
//        }
//
//        bool operator==(const fill_iterator& rhs) const
//        {
//            return (x_ == rhs.x_)&&
//				   (y_ == rhs.y_);
//        }
//
//    };
//
//
//    template <int a,int b, int c, int d> 
//    inline bool operator!=(
//        const fill_iterator< a, b, c, d>& lhs,
//        const fill_iterator< a, b, c, d>& rhs)
//    {    // test for fill_iterator inequality
//        return !(lhs == rhs);
//    }
//
//   
//} // namespace yasli_nstd
//
//
//	
//int matrix_main()
//{
//	using namespace my_nstd;
//	fill_iterator<0,0,3,3> b, e(0);
//	int i = 0;
//	for (;b!=e && i<10; ++b, ++i)
//	{
//		std::cout<<i<<": ("<<b.get_x()<<","<<b.get_y()<<"):"<<*b<<std::endl;
//	}
//	return 0;
//}