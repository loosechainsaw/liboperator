#ifndef HAS_ADDITION_OPERATOR
#define HAS_ADDITION_OPERATOR 

#include <type_traits>

namespace liboperator
{

	template<class T1, class T2>
	class has_addition_operator
	{
	private:

		class no{};

		template<typename X1, typename X2>
		static auto has(X1&& a, X2&& b) -> decltype( a + b){

		}

		static no has(...){

		}

	public:
		enum{
			value = ( !std::is_same<decltype( has(std::declval<T1>(), std::declval<T2>())),no>::value)
		};

	};


}

#endif
