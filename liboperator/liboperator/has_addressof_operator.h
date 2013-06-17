#ifndef HAS_ADDRESSOF_OPERATOR
#define HAS_ADDRESSOF_OPERATOR 

namespace liboperator
{

	template<class T>
	class has_addressof_operator
	{
	private:
		class no{};
		template<class X>
		static auto has(X&& t) -> decltype (t.operator& () );

		static no has(...);
	public:
		enum {
			value =  !std::is_same<
								  decltype(has( std::declval<T>() )),
								no>::value
		};
	};

	template<class T>
	class has_addressof_operator<T*>{
	public:
		enum {
			value = 1
		};
	};


}

#endif
