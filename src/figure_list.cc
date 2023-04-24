#include <figure/figure.h>
#include <cmath>
#include <stdexcept>

using namespace figure;
using namespace std;

FigureList::FigureList() :_figures(nullptr), _size(0) {};

FigureList::FigureList(FigurePtr* figures, int size): _size(size), _figures(new FigurePtr[_size]) {
	for (int i = 0; i < _size; ++i) 
		_figures[i] = figures[i];
}
FigureList::FigureList(FigureList& figures):_size(figures._size),_figures(new FigurePtr[figures._size]) {
	for (int i=0;i<_size;++i)
		_figures[i]=
}

FigureList::~FigureList() {
	clear();
}

FigurePtr FigureList::get_figure_by_index(int i)const {
	if (i < 0 || i>_size) {
		throw std::runtime_error("Index out of range.");
	}
	return _figures[i];
}

int FigureList::get_size()const { return _size; }

Figure FigureList::operator[](int ind) const {
	if (ind < 0 || ind >= _size) {
		throw std::runtime_error("Index out of range.");
	}
	return *_figures[ind];
}

Figure& FigureList::operator[](int ind) {
	if (ind < 0 || ind >= _size) {
		throw std::runtime_error("Index out of range.");
	}
	return _figures[ind];
}

void FigureList::add_item(int ind, Figure fig) {
	++_size;
	if (ind < 0 || ind >= _size) {
		throw std::runtime_error("Index out of range.");
	}
	for (int i = _size - 1; i >= ind; --i)
	{
		_figures[i] = _figures[i - 1];
	}
	_figures[ind] = fig;
}

void FigureList::clear() {
	if (_figures == nullptr)
		return;
	_size = 0;
	delete[] _figures;
	_figures = nullptr;
}

void FigureList::del_item(int ind) {
	if (_size <= 0) {
		throw std::runtime_error("FigureList is empty.");
	}
	for (int i = ind; i < _size - 1; ++i)
	{
		_figures[i] = _figures[i + 1];
	}
	--_size;
}

int FigureList::figure_max_volume()const {
	if (_size == 0)
		return -1;
	int ind = 0;
	double max_volume = _figures[0].figure_volume();
	for (int i = 1; i < _size; ++i) {
		double cur_volume = _figures[i].figure_volume();
		if (cur_volume > max_volume) {
			ind = i;
			max_volume = cur_volume;
		}
	}
	return ind;
}
