#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <climits>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int n);

	// Add a range of numbers via iterators
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}

	int shortestSpan() const;
	int longestSpan() const;

private:
	unsigned int     _max;
	std::vector<int> _data;
};

#endif
