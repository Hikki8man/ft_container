#ifndef FT_STACK_HPP
#define FT_STACK_HPP
#include "vector.hpp"

namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack {
		protected:
			Container c;
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;

			// Constructor
			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}

			// Destructor
			~stack() {}

			stack& operator=(const stack& other) {
				c = other.c;
				return *this;
			}

			// Public member functions
			bool empty() const {
				return c.empty();
			}

			size_type size() const {
				return c.size();
			}

			void push(const value_type& value) {
				c.push_back(value);
			}

			void pop() {
				c.pop_back();
			}

			value_type& top() {
				return c.back();
			}

			const value_type& top() const {
				return c.back();
			}

			template<class _T, class _C>
			friend bool  operator==(const stack<_T, _C>& _l, const stack<_T, _C>& _r);

			template<class _T, class _C>
			friend bool  operator<(const stack<_T, _C>& _l, const stack<_T, _C>& _r);
	};
	// Operator Overloads
	template < class T, class Container >
		bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return lhs.c == rhs.c;
		}
	template < class T, class Container >
		bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(lhs == rhs);
		}
	template < class T, class Container >
		bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return lhs.c < rhs.c;
		}
	template < class T, class Container >
		bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(rhs < lhs);
		}
	template < class T, class Container >
		bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return rhs < lhs;
		}
	template < class T, class Container >
		bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(lhs < rhs);
		}
}

#endif