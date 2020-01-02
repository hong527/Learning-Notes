template<class T>
inline  void  hash_combine(std::size_t& seed, const T& val) {
	seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template<class T>
inline  void  hash_val(std::size_t& seed, const T& val) {
	hash_combine(seed, val);
}

template<class T, class ...Types>
inline  void  hash_val(std::size_t& seed, const T& val, const Types& ...args) {
	hash_combine(seed, val);
	hash_val(seed, args...);
}

template<class ...Types>
inline  size_t  hash_val(const Types& ...args) {
	size_t  seed = 0;
	hash_val(seed, args...);
	return seed;
}

//copy from 侯捷