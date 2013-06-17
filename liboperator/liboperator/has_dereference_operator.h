#ifndef HAS_DEREFERENCE_OPERATOR
#define HAS_DEREFERENCE_OPERATOR 

namespace liboperator
{

	template<class T>
	class has_dereference_operator
	{
	private:
		class no{};
		template<class X>
		static auto has(X&& t) -> decltype (t.operator * ());

		static no has(...);
	public:
		enum {
			value =  !std::is_same<
								  decltype(has( std::declval<T>() )),
								no>::value
		};
	};


}

#endif
