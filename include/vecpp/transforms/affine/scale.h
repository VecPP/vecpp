#ifndef VECPP_TRANSFORMS_AFFINE_SCALE_H_INCLUDED
#define VECPP_TRANSFORMS_AFFINE_SCALE_H_INCLUDED

#include "vecpp/vecpp.h"

namespace vecpp {

  template<typename T>
  struct Scale {
  public:
    Scale(const Vec<T, 3>& s)
      : s_(s) {}

    Vec<T, 3> transform(const Vec<T, 3>& v) {
      return v * s_;
    }

    operator Mat<T, 4, 4>() const {
      return {  
        s_[0] , 0,     0,     0,
        0,      s_[1], 0,     0,
        0,      0,     s_[2], 0,
        0,      0,     0,     1 
      };
    }

  private:
    Vec<T, 3> s_;
  };

  template<typename T>
  Scale(const Vec<T, 3>&) -> Scale<T>;
}

#endif