#ifndef INCLUDED_CW_UTF8
#define INCLUDED_CW_UTF8
#include <cstdint>
#include <iterator>

namespace cw {

	struct utf8_const_iterator {
		using this_type         = utf8_const_iterator;
		using unit_type         = uint8_t;
		using value_type        = uint32_t;
		using unit_pointer      = const unit_type*;
		using pointer           = unit_pointer;
		using reference         = value_type;
		using difference_type   = ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;

		unit_pointer p;

		explicit utf8_const_iterator( unit_pointer p = nullptr ) : p(p) {}

		value_type operator*() const {
			unit_pointer q = p;
			unit_type unit1 = *q;

			if( ( unit1 & 0x80 ) == 0 ) {
				// 1 bytes
				return value_type(unit1);
			}

			if( ( unit1 & 0xE0 ) == 0xC0 ) {
				// 2 bytes
				unit_type unit2 = *++q;

				value_type full_code = ( ( unit1 & 0x1F ) << 6 )
									 | ( unit2 & 0x3F );
				return full_code;
			}

			if( ( unit1 & 0xF0 ) == 0xE0 ) {
				// 3 bytes
				unit_type unit2 = *++q;
				unit_type unit3 = *++q;

				value_type full_code = ( ( unit1 & 0x0F ) << 12 )
									 | ( ( unit2 & 0x3F ) << 6 )
									 | ( unit3 & 0x3F );
				return full_code;
			}

			if( ( unit1 & 0xF8 ) == 0xF0 ) {
				// 4 bytes
				unit_type unit2 = *++q;
				unit_type unit3 = *++q;
				unit_type unit4 = *++q;

				value_type full_code = ( ( unit1 & 0x07 ) << 18 )
									 | ( ( unit2 & 0x3F ) << 12 )
									 | ( ( unit3 & 0x3F ) << 6 )
									 | ( unit4 & 0x3F );
				return full_code;
			}

			return 0xFFFD; // error
		}

		unit_pointer operator->() const {
			return p;
		}

		this_type& operator++() {
			for(int i=0;i<4;++i) {
				++p;
				if( ( *p & 0xC0 ) != 0x80 )
					break;
			}
			return *this;
		}

		this_type& operator--() {
			for(int i=0;i<4;++i) {
				--p;
				if( ( *p & 0xC0 ) != 0x80 )
					break;
			}
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

	struct utf8 {
		using unit_type = uint8_t;
		using value_type = uint32_t;
		using iterator = utf8_const_iterator;
		using const_iterator = utf8_const_iterator;
	};

}

#endif
