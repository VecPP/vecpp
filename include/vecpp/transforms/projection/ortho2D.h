#ifndef VECPP_TRANSFORMS_PROJECTION_ORTHO2D_H_INCLUDED
#define VECPP_TRANSFORMS_PROJECTION_ORTHO2D_H_INCLUDED

#include "vecpp/vecpp.h"

namespace vecpp {
  template<typename T>
  struct Ortho2D {
  public:
    Ortho2D(const Vec<T, 2>& dim_x, const Vec<T, 2>& dim_y)
      : dim_x_(dim_x)
      , dim_y_(dim_y) {}

    Vec<T, 3> transform(const Vec<T, 3>& v) {
      return {
        (v[0] - dim_x_[0]) * T(2) / (dim_x_[0] - dim_x_[1]),
        (v[1] - dim_y_[0]) * T(2) / (dim_x_[0] - dim_x_[1]),
        v[2]
      };
    }

    operator Mat<T, 4, 4>() const {
 
      auto dx = (dim_x_[1] - dim_x_[0]);
      auto dy = (dim_y_[1] - dim_y_[0]);

      auto tx = (dim_x_[1] + dim_x_[0]);
      auto ty = (dim_y_[1] + dim_y_[0]);

      return {  
        T(2) / dx , 0 , -tx / dx , 0,
        0 , T(2) / dy , -ty / dy , 0,
        0, 0, 1, 0,
        0, 0, 0, 1 
      };
    }

  private:
    Vec<T, 2> dim_x_;
    Vec<T, 2> dim_y_;
  };

  template<typename T>
  Ortho2D(const Vec<T, 2>&, const Vec<T, 2>&) -> Ortho2D<T>;
}

#endif