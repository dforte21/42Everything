#include "PmergeMe.hpp"

bool	checkNum( std::string n ){
	if (n[0] == '-')
			return false;
	if(n.size() >= 10 && n.compare("2147483647") > 0)
			return false;
	for (size_t i = 0; i < n.size(); i++)
		if (!std::isdigit(n[i]))
			return false;
	return true;
}

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( char **av ){
	for (size = 0; av[size + 1]; size++){
		std::string n(av[size + 1]);
		if (!checkNum(n))
			throw invalidNumber();
	}
	vNumber.reserve(size);
	sNumber.reserve(size);
	std::pair<std::unordered_set<int>::iterator, bool> result;
	for (int i = size; i > 0; i--){
		result = sNumber.insert(atoi(av[i]));
		if (!result.second)
			throw duplicateNumber();
	}
	for (int i = 1; av[i]; i++)
		vNumber.push_back(atoi(av[i]));
}

PmergeMe::PmergeMe( const PmergeMe &c ){
	*this = c;
}

PmergeMe::~PmergeMe(){
	vNumber.clear();
	sNumber.clear();
}

PmergeMe	&PmergeMe::operator=( const PmergeMe &c ){
	if (this == &c)
		return (*this);
	this->size = c.size;
	this->vNumber = c.vNumber;
	this->sNumber = c.sNumber;
	return (*this);
}

void	PmergeMe::vMergeInsert(int left, int right, int k){
	for (size_t i = 0; i < size - 1; i++)
	{
		if (vNumber[i] > vNumber[i + 1])
			break;
		if (i == size - 2)
			throw alreadyOrdered();
	}
	if (left >= right) {
        return;
    }
    if (right - left <= k) {
        for (int i = left + 1; i <= right; i++) {
            int key = vNumber[i];
            int j = i - 1;

            while (j >= left && vNumber[j] > key) {
                vNumber[j + 1] = vNumber[j];
                j--;
            }

            vNumber[j + 1] = key;
        }
    }
    else {
        int mid = (left + right) / 2;
		vMergeInsert(left, mid, k);
       	vMergeInsert(mid + 1, right, k);
        vMerge(left, mid, right);
    }
}

void	PmergeMe::vMerge(int left, int mid, int right){
	std::vector<int> left_arr(mid - left + 1);
    std::vector<int> right_arr(right - mid);

    for (size_t i = 0; i < left_arr.size(); i++) {
        left_arr[i] = vNumber[left + i];
    }

    for (size_t i = 0; i < right_arr.size(); i++) {
        right_arr[i] = vNumber[mid + 1 + i];
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < left_arr.size() && j < right_arr.size()) {
        if (left_arr[i] <= right_arr[j]) {
            vNumber[k] = left_arr[i];
            i++;
        }
        else {
            vNumber[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_arr.size()) {
        vNumber[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_arr.size()) {
        vNumber[k] = right_arr[j];
        j++;
        k++;
    }
}

void	PmergeMe::vStartSort(){
	std::cout << "USING STD::VECTOR\nInput: ";
	for (size_t i = 0; i < 5; i++)
		std::cout << vNumber[i] << " ";
	start = std::clock();
	vMergeInsert(0, size - 1, 4);
	end = std::clock();
	double elapsedMilliseconds = (double)(end - start) / (double)CLOCKS_PER_SEC * 1000.0;
	std::cout << "...\nAfter sort: ";
	for (size_t i = 0; i < 5; i++)
		std::cout << vNumber[i] << " ";
	std::cout << "...\ntime elapsed: " << elapsedMilliseconds << "ms\n\n";
}

void	PmergeMe::sStartSort(){
	std::vector<int> vec(sNumber.begin(), sNumber.end());
	std::vector<int> tmp = vNumber;
	vNumber = vec;
	std::cout << "USING STD::UNORDERED_SET\nInput: ";
	std::unordered_set<int>::iterator it = sNumber.begin();
	for (int i = 0; i < 5; i++)
	{
		std::cout << *it << " ";
		it++;
	}
	start = std::clock();
    vMergeInsert(0, size - 1, 4);
	sNumber.clear();
    for (int i = size - 1; i >= 0; i--)
		sNumber.insert(vNumber[i]);
	end = std::clock();
	double elapsedMilliseconds = (double)(end - start) / (double)CLOCKS_PER_SEC * 1000.0;
	std::cout << "...\nAfter sort: ";
	for (size_t i = 0; i < 5; i++)
		std::cout << vNumber[i] << " ";
	std::cout << "...\ntime elapsed: " << elapsedMilliseconds << "ms\n\n";
	vNumber = tmp;
}