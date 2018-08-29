
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::end(vecpp::Vec)

```
template<typename T, std::size_t L>
constexpr T* end(Vec<T,L>& v);

template<typename T, std::size_t L>
constexpr const T* end(const Vec<T,L>& v);  
```

Returns a past-the-end iterator for the provided vector.

### Parameters

Argument | Role
---------|---------------------------------
**v**    | The vector to get the iterator from

### Return value
iterator tpast the last element.

### See also

* [begin](begin.md) : Returns an iterator to the end.