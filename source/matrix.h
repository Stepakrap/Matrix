#pragma once
#include"utmatr.h"
using namespace std;
template <class ValType>
class TMatrix : public TVector<TVector<ValType> > {
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& mt);
	TMatrix(const  TVector<TVector<ValType> >& mt);
	~TMatrix() override
	{
		delete[] pVector;
	};
	TMatrix& operator == (const TMatrix& mt);
	TMatrix& operator = (const TMatrix& mt);
	TMatrix operator + (const TMatrix& mt);
	TMatrix& operator - (const TMatrix& mt);
	TMatrix& operator* (const TMatrix& mt);
	friend istream& operator >> (istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream& operator << (ostream& out, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};
template<class ValType>
TMatrix<ValType>::TMatrix(int s) :TVector<TVector<ValType> >(s)
{
	for (int i = 0; i < s; i++)
		this->pVector[i] = TVector<ValType>(s - i, i);
}
template<class ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :TVector<TVector<ValType> >{ mt } {}
template<class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >{ mt } {}
template<class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (this != &mt)
	{
		if (this->Size != mt.Size)
		{
			delete[]this->pVector;
			this->pVector = new TVector<ValType>[mt.Size];
		}
		this->Size = mt.Size;
		this->StartIndex = mt.StartIndex;
		for (int i = 0; i < this->Size; i++) this->pVector[i] = mt.pVector[i];
	}
	return *this;
}
template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	return TVector<TVector<ValType> >::operator+(mt);
}