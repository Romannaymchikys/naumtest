template<typename T1,typename T2>
class Pair{
	T1 of_value;
	T2 s_value;
public:
	Pair() : f_value(0), s_value(0){};
	Pair(const T1 f, const T2 s) : of_value(f), s_value(s) {};
	T1 first() const { return of_value; }
	T2 second() const { return s_value; }

};