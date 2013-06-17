#ifndef HAS_SUBSCRIPT_OPERATOR
#define HAS_SUBSCRIPT_OPERATOR 

namespace liboperator
{

	template<class T>
	class has_subscript_operator
	{
	private:

		class no{};

		template<typename X1>
		static auto has(X1&&) -> decltype( a.operator[](0)){

		}

		static no has(...){

		}

	public:
		enum{
			value = ( !std::is_same<decltype( has(std::declval<T>())),no>::value)
		};

	};


}

#endif