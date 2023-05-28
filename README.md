# Title: The Quest for the Magical Iterators

Background Story: In the ancient kingdom of Iteratia, there exists a magical container that has the power to hold different types of mystical elements. These elements have various properties and abilities that are essential for maintaining the balance of the kingdom. Over time, the knowledge of harnessing the power of these elements was lost. It is said that three powerful iterators were created to unlock the potential of the magical container. These iterators represent different orders of traversal through the container, revealing different aspects of the mystical elements. The kingdom is now in turmoil, and the wise King seeks the help of a talented programmer to rediscover the power of these iterators.
Objective: In this assignment, you will create a custom container class named "MagicalContainer" to store mystical elements represented by integers. You will also implement three custom iterator classes, each representing a different order of traversal through the container. By the end of this assignment, you should have a deeper understanding of custom iterators and their applications in C++.

Instructions:
1.	Create a user-defined container class named "MagicalContainer" that can store integers representing mystical elements. Implement necessary methods for adding elements, removing elements, and retrieving the size of the container. You can use a dynamic array or any other suitable data structure for internal storage.
2.	Create three custom iterator classes named "AscendingIterator", "SideCrossIterator", and "PrimeIterator" that will allow traversal of elements in the MagicalContainer class in ascending order, cross order, and prime numbers only, respectively. Each iterator should support the following operations:

operations:

•	Default constructor

•	Copy constructor

•	Destructor

•	Assignment operator

•	Equality comparison (operator==)

•	Inequality comparison (operator!=)

•	GT, LT comparison (operator>, operatorn<) all comparison operators only valid for iterators of the same type of order and should compair the location of the iterator in the container and not the element inside. Example bellow. Using operators on iterators of differant type or differant containers should throw an examtion. 
 
•	Dereference operator (operator*)

•	Pre-increment operator (operator++)

•	begin(type): Returns the appropriate iterator (ascending, cross, or prime) pointing to the first element of the container based on the specified type.

•	end(type): Returns the appropriate iterator (ascending, cross, or prime) pointing one position past the last element of the container based on the specified type.

For expample: say our container contains the numbers 1,2,4,5,14 the iterators will return the elements in the following order:

• Ascending: 1,2,4,5,14   
operator> should return true on 5>2, 14>1

• prime: 2,5
operator> should return true on 5>2
• cross: 1,14,2,5,4  (one from the start then one from the end)
operator> should return true on 5>14, 2>1, 4>14

**All iterators should work in O(1) in both memory and time complexity.** Do note that's only the Iterator operation should be in O(1) in memory and time.
The container can insert and erase elements in O(N).  
Iterators should **NOT** be detached from the main container. If one add's an element to a container after an iterator is created the iterator should know the element return it should its turn will come. If the element is located in a position before curent the location of the iterator it will not return it. 
In our case, if one uses PrimeIterator and it points to 5, adding 3 will not change the iterator, and the ++ operator will put it at end(). However, adding 7 to the container will make the ++ operator point the iterator to 7.

To simplify the implementation, we will ignore the case where an iterator points to an element while we delete that element. In such a case, the iterator is no longer valid. There is no need to implement a solution for this situation; it's up to the programmer not to use it.



**חלק א**: יש לכתוב: 

* קובץ כותרת הכולל את כל הפונקציות הדרושות (ללא מימוש). שימו לב: הכותרות צריכות להיות נכונות בהתאם למה שנלמד בהרצאות - מומלץ לחזור על החומר לפני שמתחילים לכתוב.
* בדיקות מקיפות לכל הפונקציות הדרושות.
  
כיתבו את כל הקבצים הדרושים כך שהפקודות הבאות יעבדו ללא שגיאות:

<div dir='ltr'>

    make demo && ./demo
	make test && ./test

</div>

מומלץ גם להריץ:

<div dir='ltr'>

    make tidy
    make valgrind

</div>

אין לשנות קבצים קיימים אלא רק להוסיף קבצים חדשים.

בהצלחה
