#ifndef INCLUDED_CW_STRING
#define INCLUDED_CW_STRING
#include <vector>
#include <cstring>

namespace cw {

	template<typename Encoding>
	struct string {
		using encoding       = Encoding;
		using value_type     = typename encoding::value_type;
		using unit_type      = typename encoding::unit_type;
		using unit_iterator  = typename std::vector<unit_type>::iterator;
		using iterator       = typename encoding::iterator;
		using const_iterator = typename encoding::const_iterator;

		std::vector<unit_type> units;
		
		string() = default;

		explicit string( const char* c ) {
			auto bytes = std::strlen(c);
			units.resize( bytes );
			std::copy( c, c + bytes, units.begin() );
		}

		const_iterator begin() const noexcept {
			return const_iterator( units.data() );
		}

		const_iterator end() const noexcept {
			return const_iterator( units.data() + units.size() );
		}

		iterator begin() noexcept {
			return iterator( units.data() );
		}

		iterator end() noexcept {
			return iterator( units.data() + units.size() );
		}

	};

}

#endif
