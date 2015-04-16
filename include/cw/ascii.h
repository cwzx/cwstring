#ifndef INCLUDED_CW_ASCII
#define INCLUDED_CW_ASCII
#include <iterator>

namespace cw {

	template<typename T = char>
	struct simple_iterator {
		using this_type         = simple_iterator<T>;
		using unit_type         = T;
		using value_type        = unit_type;
		using reference         = unit_type&;
		using pointer           = unit_type*;
		using difference_type   = ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;

		pointer p;

		explicit simple_iterator( pointer p = nullptr ) : p(p) {}

		reference operator*() const {
			return *p;
		}

		pointer operator->() const {
			return p;
		}

		this_type& operator++() {
			++p;
			return *this;
		}

		this_type& operator--() {
			--p;
			return *this;
		}

		this_type operator++(int) {
			auto old = *this;
			++(*this);
			return old;
		}

		this_type operator--(int) {
			auto old = *this;
			--(*this);
			return old;
		}

		bool operator==( this_type rhs ) const {
			return p == rhs.p;
		}

		bool operator!=( this_type rhs ) const {
			return !( *this == rhs );
		}

	};

	template<typename T>
	struct simple_encoding {
		using unit_type = T;
		using value_type = unit_type;
		using iterator = simple_iterator<unit_type>;
		using const_iterator = simple_iterator<const unit_type>;
	};

	using ascii = simple_encoding<char>;

}

#endif
