#ifndef HAS_ASSIGNMENT_OPERATOR
#define HAS_ASSIGNMENT_OPERATOR 

namespace liboperator
{

	template<class T1, class T2>
	class has_assignment_operator
	{
	private:
		class no{};
		template<class X1, class X2>
		static auto has(X1&& a, X2&& b) -> decltype (a = b);

		static no has(...);
	public:
		enum {
			value = ( !std::is_same<decltype((has( std::declval<T1>(), std::declval<T2>()))),no>::value)
		};
	};


}

#endif
