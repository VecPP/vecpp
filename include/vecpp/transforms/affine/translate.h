#ifndef VECPP_TRANSFORMS_AFFINE_TRANSLATE_H_INCLUDED
#define VECPP_TRANSFORMS_AFFINE_TRANSLATE_H_INCLUDED

#include "vecpp/vecpp.h"

namespace vecpp {

  template<typename T>
  struct Translate {
  public:
    Translate(const Vec<T, 3>& t)
      : t_(t) {}

    Vec<T, 3> transform(const Vec<T, 3>& v) {
      return v + t_;
    }

    operator Mat<T, 4, 4>() const {
      return {  
        1, 0, 0, t_[0],
        0, 1, 0, t_[1],
        0, 0, 1, t_[2],
        0, 0, 0, 1 
      };
    }

  private:
    Vec<T, 3> t_;

  };

  template<typename T>
  Translate(const Vec<T, 3>&) -> Translate<T>;
}

#endif