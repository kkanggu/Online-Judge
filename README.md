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

***
### Day 12
#14889 Complete. (Start & Link)
>	I used '4 != ...', and it's only for 8 members.   
>	So the code I wrote was wrong.

#1003 Complete. (Fibonacci)
>	Dynamic programming problem.   
>	First I used bad fibonacci algorithm, it exceeds time limit.   
>	So I changed to use dynamic programming.

#9184 Complete. (Funny Function)
>	DP problem.   
>	I try to understand this recursive function, but I can't figure out formula.   
>	So I used 21 * 21 * 21 spaces to solve this.   
>	The code I submitted took about 128ms, some people took only 8ms.   
>	I saw their code, and they use recursive function. I don't know why.


***
### Day 13
#1904 Complete. (Silver III)
>	DP problem.   
>	The rule of this problem equals Fibonacci.   
>	First I used dynamic array, but it took about 8ms & 5924 KB.   
>	So I changed to use only 3 variables. Then it changed to 4ms & 2016 KB.

#9461 Complete. (Wave Formula)
>	DP problem.   
>	Suppose f(n) : The length of triangle   
>	From f(6), f(n) = f(n-5) + f(n-1)   
>	I thought int would be enough. But it's wrong. So I change to long long.

***
### Day 14
#1149 Complete. (RGB Street)
>	DP problem.   
>	This is simillar as pebble problem that I learned last cemester.   
>	Painting red last is f(n,R). Green is f(n,G), Blue is f(n,B).   
>	If I want to get f(n,R), minimum value of ( f(n-1 , G) , f(n-1 , B) ) + red value.   
>	DP Problem, so I can use only 6 spaces. ( int irgColorMin [ 2 ] [ 3 ] )

***
### Day 15
#1932 Complete. (Integer Triangle)
>	DP problem.   
>	I try to save memory, I used irgTriagleMax [ 501 ] instead of [ 500 ] [ 500 ]   
>	So I can save memory, but it took about 28ms.   
>	I think that token processing is the key to save more time.   
>	If I find better way, maybe it will took less time.

#2579 Complete. (Climbing the Stairs)
>	DP problem.   
>	First, I misunderstand the problem. I thouht that climb one step three times in a row is invalid.   
>	But if I climb two step, then it also counts to one step.

#1463 Complete. (Make 1)
>	DP problem.   
>	I couldn't figure out the way to solve this problem.   
>	Suddenly, I remember that this is dp problem. So I solved it.   
>	I used dynamic allocation, if I input 2934, CRT error had occured.   
>	I couldn't find the reason, and I changed to static array with huge memory.

***
### Day 16
#10844 Complete. (Easy Stairs)
>	DP problem.   
>	First I thought that long long is enough to store the data, but it exceeds the limit.   
>	So I changed to unsigned int, and divide it to 1,000,000,000 every steps.

#2156 Complete. (Wine Tasting)
>	DP problem.   
>	This problem is simillar as #1463.

#11053 Complete. (The Longest Increasing Partial Sequence)
>	DP problem.   
>	The key to solve this problem is accumulating sequence.   
>	Because of increasing sequence, I have to check whether effective sequence exist or not.   
>	If I save 10 200 and I found that 10 20 is valid, then I have to change to 10 20.   
>	Sure former long sequence already exists. All I have to check is only last number of sequence.

#11054 Complete. (The Longest Bionic Sequence)
>	DP problem.   
>	Expansin of #11053, it was hard than I thought.   
>	I had to think 3 ways. Ascending, descending, ascending changes to descending.   
>	I thought very wrong, so I debugged too many times.

***
### Day 17
#2565 Fail. (Electric Wire)
>	DP problem.   
>	First, I thought I have to calculate only ascending lis.   
>	But it was wrong. If I put n, (a,b) a+b=n, then I have to remove n-1 wires.   
>	So I calculate ascending lis and decending lis, and all the examples shared by users were correct.   
>	But Baekjoon says I'm wrong in 45% of the progress.   
>	I'll try it tomorrow.

***
### Day 18
#2565 Fail. (Electric Wire)
>	I was right. I have to check only ascending lis.   
>	Even if descending, the sequence of number is ascending sequence.   
>	I failed exactly 54% of the progress. I don't know what to do.

***
### Day 19
#9251 End. (LCS)
>	DP Problem.   
>	I learned this algorithm last cemester, but I forgot it.   
>	I tried to find the way, but I couldn't. So I saw the lecture that I learned last cemester.   
>	It wasy easy. Check every cases with last character.