#ifndef HAS_SUBTRACTION_OPERATOR
#define HAS_SUBTRACTION_OPERATOR 

namespace liboperator
{

	template<class T1, class T2>
	class has_subtraction_operator
	{
		typedef typename std::remove_pointer< typename std::remove_reference<T1>::type >::type AT1;
		typedef typename std::remove_pointer< typename std::remove_reference<T2>::type>::type AT2;
	private:

		class no{};

		template<typename X1, typename X2>
		static auto has(X1&& a, X2&& b) -> decltype( a - b){

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