Online Judge Code
=================

Solved.ac - kkanggu
---------------------------

### Day 1
#1041 at Silver 1 (Dice)

***
### Day 2
#1041 Failed. (Tried 9 times)   
>I misunderstand about this problem.   
>I just thought that I can arrange the dice.   
>Size N, I calculate 3 things.   
>Dice with 3 Exposed plane is only 4.   
>Dice with 2 Exposed plane is 4 * ( 2N - 3 ).   
>Dice with 1 Exposed plane is ( N-2 ) * ( N-1 ) * 4 + ( N-2 ) * ( N-2 ).   
>And I don't why I'm wrong. I'll try this later.   

#1012 ing. (Organic Cabbage)      

***
### Day 3
#1012 Complete. (Changed coding style)   
>Online Judge is for short and efficient code.   
>So I'll use class only if when I need it.   
>Input every condition, and use DFS.   
>If left right top bottom is not end, then check and add to DFS.   

#2798 Complete. (BlackJack)
>This problem is sum of 3 different cards.   
>So I use 3 for functions.   

#2231 Complete. (SplitSum)   
>First, I design to check all the numbers at finded digits. (54321, then 10,000 to 99,999)   
>But it took times about 60 ms, so I changed the logics.   
>If the number N is 5 digits, then minum of possible number is N - 5 * 9.   
>Then it took about 0 ms.

***
### Day 4
#7568 First try. (Bulks)   
>	I couldn't think efficient algorithm to make rank.   
>	I'll solve this problem tomorrow.

***
### Day 5
#7568 Complete. (Bulks)   
>	This problem has a problem.   
>	This shows the rank should be (2, 2, 1, 2, 5), not (2, 2, 1, 2, 3)   
>	But it was 100% success if I run the code that gives answer (2, 2, 1, 2, 3)   
>	But many people including me suffered because of this.   
>	In fact, I fail to sort former problem. I wanna get some advice to solve this. And I saw this problems.

***
### Day 6
#1018 Complete. (Fill chess board)   
>	It was easy. I checked every 8x8 board.   
>	I split into two pieces, which have to be black, and have to be white.   
>	Then I checked one color's count of each blocks.   
>	There are 2 ways to fill the chess board, and check either and find minimum value.   

#1436 Complete. (Movie director shaun)   
>	I try to find formula, but I can't find it. So I found all of cases ignorantly.   
>	I assume that if N is 10,000, numbering can't be over 6660000.   
>	I check every cases that numbering includes '666'.

***
### Day 7
#15649 Complete. (N & M)   
>	First, I skipped sorting part, because it seems too easy.   
>	At first, I designed to use cout. Because of it, the time exceeds.   
>	So I change to printf, then total measured time is 28ms.   
>	The time limit is 1 second. But I enter 8 8, it took too much time.   
>	Maybe the answer of this problem designed not to input too high value.


***
### Day 8
#15650 ~ #15652 Complete. (N & M 2, 3, 4)   
>	Similar to #15649 (N & M). I'm not gonna write details.

#9663 Complete. (N Queen)   
>	Backtracking problem.   
>	I checked the queen is valid as a new function.

***
### Day 9
#2580 Complete. (Sudoku)   
>	This problem has 2-way solutions.   
>	First way is Backtracking. The intention of this problem.   
>	But difficult sudoku needs too much time. That's why I try to solve second way.   
>	It's to record the number available in each line.   
>	Sure if provided problem is easy, then this way spend too much time.   
>	But the harder sudoku, the better efficiency.   
>	Also there are lots of good ways to solve the sudoku, as expanding the program, this program will become much better.   
>	But this is judge problem. So I used first way to solve this problem.


***
### Day 10
#14888 Complete. (Insert Operator)   
>	Backtracking problem   
>	I checked each operator is available, and if valid, I do backtracking.

***
### Day 11
#14889 Fail. (Start & Link)
>	Backtracking problem   
>	I solved example, but the submitted code is wrong.