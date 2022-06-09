#include <iostream>

using namespace std;


template<typename T>
class MySmartPointer
{
private:
	T* m_ptr;
	unsigned int* m_counter;

public:
	MySmartPointer(T* ptr)
		: m_ptr(ptr)
		, m_counter(new unsigned int(1))
	{

	}

	~MySmartPointer()
	{

		*m_counter -= 1;
		if (*m_counter == 0)
		{
			if (m_ptr)
			{
				delete m_ptr;
			}
			if (m_counter)
			{
				delete m_counter;
			}
		}
	}

	MySmartPointer& operator=(MySmartPointer& a)
	{
		if (&a == this)
		{
			return *this;
		}

		if (!m_ptr)
		{
			*m_counter -= 1;
			if (*m_counter == 0)
			{
				delete m_ptr;
			}
		}

		m_ptr = a.m_ptr;
		m_counter = a.m_counter;
		*m_counter += 1;

		return *this;
	}

	MySmartPointer(MySmartPointer& a)
	{
		m_counter = a.m_counter;
		*m_counter += 1;
		m_ptr = a.m_ptr;
		//a.m_ptr = nullptr;
	}


	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

};

int main()
{
	setlocale(LC_ALL, "ru");
	MySmartPointer<int> pointer(new int(7));
	MySmartPointer<int> pointer1(new int(9));
	MySmartPointer<int> pointer2 = pointer1;
	MySmartPointer<int> pointer3 = pointer1;
	MySmartPointer<int> pointer4 = (new int(14));
	
	return 0;
}