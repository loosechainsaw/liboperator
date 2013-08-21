#ifndef HAS_DIVISION_OPERATOR
#define HAS_DIVISION_OPERATOR 

namespace liboperator
{

	template<class T1, class T2>
	class has_division_operator
	{
	private:

		class no{};

		template<typename X1, typename X2>
		static auto has(X1&& a, X2&& b) -> decltype( a / b){

		}

		static no has(...){

		}

	public:
		enum{
			value = ( !std::is_same<decltype( has(std::declval<AT1>(), std::declval<AT2>())),no>::value)
		};

	};


}

#endif