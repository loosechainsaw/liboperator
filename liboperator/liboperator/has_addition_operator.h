
#ifndef HAS_ADDITION_OPERATOR
#define HAS_ADDITION_OPERATOR 

namespace liboperator
{

	template<class T1, class T2>
	class has_addition_operator
	{
	private:

		typedef char no;

		static auto has(T1* a, T2* b) -> decltype( *a + *b);

		static char has(...);

	public:
		enum{
			value = (sizeof( has(new T1(), new T2())) != sizeof(no))
		};

	};

	


}

#endif