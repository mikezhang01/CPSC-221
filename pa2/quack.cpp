/**
 * @file quack.cpp
 * Implementation of the Quack class.
 *
 */

template <class T>
Quack<T>::Quack() {
    /**
     * @todo Your code here!
     */
    data; 
    n1 = 0;
    n2;

}

/**
 * Adds the parameter object to the right of the Quack.
 *
 * @param newItem object to be added to the Quack.
 */
template <class T>
void Quack<T>::pushR(T newItem) {
    /**
     * @todo Your code here!
     */

    data.push_back(newItem);
}

/**
 * Removes the object at the left of the Quack, and returns it to the
 * caller.
 *
 * See .h file for implementation notes.
 *
 * @return The item that used to be at the left of the Quack.
 */
template <class T>
T Quack<T>::popL() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    T first = data[n1];
    n1++;

    //data.erase(data.begin());
    //data[index] = nullptr; 

    //resize

    int count = n1;

    int required = data.size() - count;   

    if (count >= required) {
        vector<T> data1;
        while (count < data.size()) {
            data1.push_back(data[count]);
            count++;
        }
        data = data1;
        n1 = 0;
    }
    
    return first;
}
/**
 * Removes the object at the right of the Quack, and returns it to the
 * caller.
 *
 * @return The item that used to be at the right of the Quack.
 */
template <class T>
T Quack<T>::popR() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    T last = data.back();
    data.pop_back();

    int count = n1;

    int required = data.size() - count;   

    if (count >= required) {
        vector<T> data1;
        while (count < data.size()) {
            data1.push_back(data[count]);
            count++;
        }
        data = data1;
        n1 = 0;
    }

    return last;
}

/**
 * Finds the object at the left of the Quack, and returns it to the
 * caller. Unlike popL(), this operation does not alter the quack.
 *
 * @return The item at the front of the quack.
 */
template <class T>
T Quack<T>::peekL() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    T first = data[n1];
    return first;
    //return T();
}

/**
 * Finds the object at the right of the Quack, and returns it to the
 * caller. Unlike popR(), this operation does not alter the quack.
 *
 * @return the value of The item at the right of the quack.
 */
template <class T>
T Quack<T>::peekR() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    T last = data.back();
    return last;

}

/**
 * Determines if the Quack is empty.
 *
 * @return bool which is true if the Quack is empty, false otherwise.
 */
template <class T>
bool Quack<T>::isEmpty() const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    if (data.size() == 0) {
        return true;
    }
    return false;
}
