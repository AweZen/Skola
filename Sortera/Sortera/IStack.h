#pragma once
template<typename T>
class IStack
{
public:
	virtual ~IStack() = 0 {};
	virtual void push(const T& element) = 0;
	virtual T pop() noexcept(false) = 0;
	virtual T peek()const throw(...)= 0;
	virtual bool isEmpty()const = 0;
};