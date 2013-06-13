
#ifndef HAS_ADDITION_OPERATOR
#define HAS_ADDITION_OPERATOR 

namespace liboperator
{

	template<class T1, class T2>
	class has_addition_operator
	{
	private:

		typedef char no;

		template<typename X1, typename X2>
		static auto has(X1 a, X2 b) -> decltype( a + b){

		}

		static no has(...){

		}

	public:
		enum{
			value = (sizeof( has(T1(), T2())) != sizeof(no))
		};

	};

	template<>
	class has_addition_operator<char,char>
	{
	public:
		enum{
			value = true
		};

	};


}

#endif