#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	
	template< class T1, class T2 >
		struct pair {
			T1 first;
			T2 second;

			pair() : first(), second() {}
			pair(const T1& a, const T2& b) : first(a), second(b) {}
			template< class U1, class U2 >
			pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}
			~pair() {}

			pair& operator=(const pair& other) {
				first = other.first;
				second = other.second;
				return *this;
			}
		};
		
		template< class T1, class T2 >
		bool operator==(const pair<T1, T2>& a, const pair<T1, T2>& b) {
			return a.first == b.first && a.second == b.second;
		}

		template< class T1, class T2 >
		bool operator!=(const pair<T1, T2>& a, const pair<T1, T2>& b) {
			return !(a == b);
		}

		template< class T1, class T2 >
		bool operator<(const pair<T1, T2>& a, const pair<T1, T2>& b) {
			return a.first < b.first || (!(b.first < a.first) && a.second < b.second);
		}

		template< class T1, class T2 >
		bool operator>(const pair<T1, T2>& a, const pair<T1, T2>& b) {
			return b < a;
		}

		template< class T1, class T2 >
		bool operator<=(const pair<T1, T2>& a, const pair<T1, T2>& b) {
			return !(b < a);
		}

		template< class T1, class T2 >
		bool operator>=(const pair<T1, T2>& a, const pair<T1, T2>& b) {
			return !(a < b);
		}

		template< class T1, class T2 >
		pair<T1, T2> make_pair(const T1& a, const T2& b) {
			return pair<T1, T2>(a, b);
		}
}

#endif