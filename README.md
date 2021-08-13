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

***
### Day 20
#1912 Fail. (Sequencial Sum)
>	DP Problem.   
>	I designed to save memory, so I used array that has only 2 components.   
>	I failed this, and I'll try it tomorrow.

***
### Day 21
#1912 End. (Sequencial Sum)
>	I found the problem.   
>	Line 40, sequnce is still sequencial, so I have to check each step is better than old one.   
>	Original code is bad, because irgMax [ 0 ] is changed to low value.

#12865 End. (Knapsack)
>	DP Problem.   
>	I learned this solution with backtracking. I didn't know how to solve this with DP.   
>	I searched this, and I found dp solution using huge memory.   
>	I can't find better way, so I used it. This take too many memories.

#11047 End. (Coin 0)
>	Greedy Algorithm   
>	Typical greedy algorithm problem. easy

***
### Day 22
#1931 Fail. (Assign Meeting Room)
>	Greedy Algrithm   
>	I thought very wrong. I try to make array that can be timetable, and try to use it.   
>	But the limit of time is 2^31-1. So I can't use this.   
>	Before recognizing that, I used tuple to use shortest time first.   
>	I commit my wrong code. And I'll change it and solve.

***
### Day 23
#1931 End. (Assign Meeting Room)
>	I used greedy algorithm, that only compare the end time of meeting.   
>	It took about 40ms. I think sorting algorithm took lots of time.

#11399 End. (ATM)
>	Greedy Algorithm   
>	Too easy. Sort the table and add. First have to add iNum times, second iNum - 1 times, ... last 1 time.

#1541 Fail. (Lost Parenthesis)
>	Greedy Algorithm   
>	Try + first, and - everthing.   
>	I failed to handle vector. I'll fix this.

***
### Day 24
#1541 End. (Lost Parenthesis)
>	I used only vector.   
>	Tried + first, and - everything. It took about 0ms.

#13305 End. (Gas Station)
>	Greedy Algorithm.   
>	I used pair and vector. Sort the price & index pair, and do greedy.   
>	It took about 84ms and 8196KB.   
>	And I saw brilliant easy solution.   
>	During processing input, do greedy. If input is higher, keep process. If input is lower, then stop using former price and use new price.   
>	That solution just took about 40ms and 1388KB. I learned good solution.

***
### Day 25
#5086 End. (Multiple and Divisor)
>	Integer theory and Combinatorics   
>	Too easy

#1037 End. (Divisor)
>	Integer theory and Combinatorics   
>	Too easy

#2609 End. (GCD and LCM)
>	Integer theory and Combinatorics   
>	Too easy

#1934 End. (LCM with Euclidean)
>	Integer theory and Combinatorics   
>	Get LCM with Euclidean algorithm. Too easy

#2981 ing. (Inspection)
>	Integer theory and Combinatorics   
>	Get LCM and print all the divisors of LCM.   
>	I have to get all the divisors. The previous process was complete.

***
### Day 26
#2981 End. (Inspeciton)
>	Integer theory and Combinatorics   
>	First, get GCD with the difference of each elements.   
>	Then get all the divisors, and erase multiple elements. If GCD is n^2, then vector is ... n n ...   
>	Last, print divisors. It's not easy problem, but it was a fun.

***
### Day 27
#3036 End. (Ring)
>	Integer theory and Combinatorics   
>	Get GCD with first input and other input, and print input / GCD. Too easy

#11050 End. (Binomial Coefficient)
>	Integer theory and Combinatorics   
>	Same as Combination. Too easy

#11051 End. (Binomial Coefficient 2)
>	Integer theory and Combinatorics   
>	Too big size, even long long can't put it. So I had to use Pascal's Triangle.

#1050 End. (Construct Bridge)
>	Integer theory and Combinatorics   
>	Use Pascal's Triangle. Reuse #11051.

#9375 End. (Fashion King Shin)
>	Integer theory and Combinatorics   
>	Just number of case problem. Count by clothes, and just multiply it. Easy

***
### Day 28
#1676 End. (0 of Factorial)
>	Integer theory and Combinatorics   
>	Too easy. I just have to count 5. 10 is 2 * 5, and 2 is more than 5.

#2004 End. (0 of Combination)
>	Integer theory and Combinatorics   
>	First, I tried to calculate efficiently. But it was too complex.   
>	So I changed the way. calculate 1 to N, 1 to N - M, 1 to M.   
>	Sometimes it's better not to be efficient.

#2630 End. (Create Colored Paper)
>	Divide and Conquer   
>	It was easy. Check big paper, if it's not one paper, divide it in 4 pieces. Do former steps again.

***
### Day 29
#1992 End. (Quad Tree)
>	Divide and Conquer   
>	Similar as #2630. Change the sequence that divide into 4 pieces, and add print '(' and ')'.

#1780 End. (Number of Paper)
>	Divide and Conquer   
>	Similar as #2630. #2630 is 2^n paper, this is 3^n paper. I had to change a few lines.   
>	Maximum array size if [ 2187 ] [ 2187 ], so former token process using sstream took too much time.   
>	I changed to scanf, and simplified condition loop. 852ms changed to 572ms.

***
### Day 30
#1629 End. (Multiply)
>	Divide and Conquer   
>	I approached with using binary. Maximum is about 2b(2000m), so I thought binary is the key to solve.   
>	array [ 0 ] is B, [ 1 ] is B^2 % C, [ 2 ] is [ 1 ]^2 % C...   
>	If input is 11 22 33, then the answer is 11^22 % 33.   
>	22 is 10110 in binary. I added each result into array, and multiply each members.   
>	Multiply [ 1 ] [ 2 ] [ 4 ] , with dividing into C.

***
### Day 31
#11401 ing. (Binomial Coefficient 3)
>	Divide and Conquer   
>	I have to use Fermat's little Theorem. Without hint, I'll not find out the way.   
>	My code has some problem, it don't work well. I'll try tomorrow.

***
### Day 32
#11401 End. (Binomial Coefficient 3)
>	Divide and Conquer   
>	I found the problem. I used 'iK = Prime - 2', and iK change to Prime, not Prime - 2.   
>	I don't why. I fix this, and the problem was solved.

#2740 End. (Multiply Matrix)
>	Divide and Conquer   
>	I solved this problem using 3 for loop.   
>	I'm correct, but there's more effective way. It's Strassen algorithm.   
>	Maximum size of this problem is 100, so I can use for loop. But if it's more huge, I need to use Strassen algorithm and divide and conquer.

#10830 ing. (Matrix Squared)
>	Divide and Conquer   
>	I have to use Strassen algorithm. But it has a problem.   
>	I have to make too many small matrix, and it need too many coding for efficiency.   
>	Maybe I thought wrong. I have to find more easy and efficient way.

***
### Day 33
#10830 End. (Matrix Squared)
>	Divide and Conquer   
>	I thought very wrong. If I use Strassen algorithm, this program will be too heavy and big.   
>	I have to overload plus & multiply matrix functions.   
>	Also having M1 to M7 will took too much time. I just multiplied common way.

#11444 End. (Fibonacci 6)
>	Divide and Conquer   
>	I had to use matrix.   
>	( 1 1 )^n = ( Fn+1 Fn )   
>	( 1 0 )       ( Fn     Fn-1 )   
>	I used this algorithm.

***
### Day 34
#6549 ing. (Biggest Rectangle in Histogram)
>	Divide and Conquer   
>	I can't find the way to use divide and conquer, so I used stack.   
>	I can solve ascending, but descending has a problem. I'll fix this.

***
### Day 35
#6549 End. (Biggest Rectangle in Histogram)
>	Divide and Conquer   
>	I found the way. If ascending, just push and calculate later.   
>	If descending, then calculate high rectangle, and transfer it to low.   
>	I got 1 3 5 and input 2. Calculate 5, then change to 1 3 and input 2.   
>	Still descending, so calculate 3 and change to 1 and input 2.   
>	Then stack has 1 2. And calculate this later.

***
### Day 36
#2261 Fail. (The Closest Dots)
>	Divide and Conquer || Line Sweeping   
>	I used divide and conquer, and I failed.   
>	At 11%, time exceeds. I'll fix the problem.

***
### Day 37
#2261 Fail. (The Closest Dots)
>	Line Sweeping   
>	I still failed at 11% with time exceed, so I changed to use line sweeping.   
>	But, still at 11%, time exceeds. I'll fix it again.

***
### Day 38
#1920 End. (Find Number)
>	Binary Search   
>	I changed to use BufferReader instead of Scanner.   
>	I reduced memory about 60%, also reduced time about 50-60%.

#10816 End. (Number Card 2)
>	Binary Search   
>	System.out.println took too much time, so I changed it.   
>	I used BufferedWriter and StringBuilder either, StringBuilder took less time and memory.

***
### Day 39
#1654 End. (Cut the LAN)
>	Binary Search   
>	Sort the array, and do binary search with the highest value.

#2805 End. (Cut the Tree)
>	Binary Search   
>	Sort the array, and do binary search with the highest value.

#2110 End. (Install the Router)
>	Binary Search   
>	Sort the array, and do binary search with checking router can be placed.   
>	To check the routher can be placed, I have to place every router.

***
### Day 40
#1300 Fail. (The Kth Number)
>	Binary Search   
>	I failed. I'll solve this.

***
### Day 41
#1300 End. (The Kth Number)
>	Binary Search   
>	The problem was Integer. The type of variable that count numbers is int.   
>	But, It can be over INT_MAX. So I changed to long, and it works.

#12015 End. (LIS 2)
>	Binary Search   
>	Solution is similar as #11053.   
>	At #11053, I used array to store. But the data can be 1m, so I used vector.   
>	Also vector can be huge, I changed linear search to binary search.

#9765 End. (6 Equations)
>	Math   
>	Easy math problem. Setting the condition is important.

#11066 Fail. (Merge Files)
>	DP   
>	I need to find best merge algorithm. Merging the least file size is not best algorithm.

***
### Day 42
#11066 End. (Merge Files)
>	DP   
>	First, I used recursive function and stack to calculate the sum.   
>	But it took too much time, I had to use Memoization.   
>	I used 2-dimension array to store the time. [ i ] [ j ] means the time to merge ith file to jth file.   
>	Because of algorithm, Stack didn't work well. So I used array to store sum. [ i ] means the sum of 0th file to i-1th file.

***
### Day 43
#11049 End. (Sequence of Matrix Multiplicaton)
>	DP   
>	Similar as #11066.   
>	Final multiplication can be 1 * 2 * 3, or 100 * 200 * 300.   
>	So I have to compare this. After compare all the cases, and then just return that value.

#1520 End. (Downhill)
>	DP   
>	I think this is the best problem of DP problem.   
>	I thought for long time to find the way. Finally I realized that this is very simple.   
>	If I wanna get ( i , j ), then see the points up, down, left, right.   
>	If it's not out of bounds and possible to cross over current point, just add.   
>	This is recursive function, so it check points (  0 to i , 0 to j ).

#10942 End. (Palindrome)
>	DP   
>	Easy dp problem.   
>	It took too many memories, so I changed to use boolean instead of int.   
>	But there was no big difference. Memory reduced about 8%, time reduced about 2%.

***
### Day 44
#2629 End. (Balance Scale)
>	DP   
>	I had to use memoization, and it's little complicated.   
>	So I used limited memoization. Memoi [ i ] [], i means I can use ith to nth weight.

#2293 End. (Coin 1)
>	DP   
>	First, I used recursive function as I used before.   
>	It took about 388ms, but others just took about 152ms. And I figure out I solved complicated.   
>	It's a DP problem. To earn kth value, I have to earn k-1th value.   
>	This problem is very easy. Get input value, and loop. That's it.

#7579 Fail. (Application)
>	DP   
>	It's similar as Knapsack problem.   
>	First, I used Memoization with rest memory. But memory can be 100m, it used too much memories.   
>	So I changed to use with total additional memory. But it works wrong. I'll fix it.

***
### Day 45
#7579 Fail. (Application)
>	DP   
>	I failed this at 23%. What I'm writing is code simplicity and efficiency.   
>	I used recursive function like knapsack. Whether use this or not, and check next app.   
>	If total application is 20, the worst case, I call function about 1m(2^20)   
>	Sure I can skip some procedure, it can be reduced to 100k(1/10)   
>	But if I concentrate on DP, I can loop about 20k to solve this problem.   
>	If max of restarting cost over 10k, I have to find better way.   
>	But at this problem, DP is very easy and efficient way to solve.

#7579 End. (Application)
>	DP   
>	DP is easy way to solve this problem.   
>	Restarting memory is c, application memory is a.   
>	Make array size of sum of c, and check every app with every c.   
>	If loop starts from bottom, it add multiple times with one app. So I had to start from top.   
>	I had to get minimum c with maximum a, so compare with Integer.max.

***
### Day 46
#1260 End. (DFS and BFS)
>	DFS & BFS   
>	DFS & BFS tutorial problem.

#2606 End. (Virus)
>	DFS & BFS   
>	Use DFS or BFS, and count the vertex. That's it.

#2667 End. (Numbering Complex)
>	DFS & BFS   
>	Use DFS or BFS. and count the vertex.   
>	Do DFS 2-dimension array not graph. That's the difference.

***
### Day 47
#2178 End. (Maze Seek)
>	DFS & BFS   
>	First, I used DFS. But it sought too much levels, time exceeded. So I changed to use BFS.   
>	Start from the first( [ 0 ] [ 0 ]). Seek with BFS, update to minimum lengh.

#7576 End. (Tomato 2D)
>	DFS & BFS   
>	Similar to #2178, but starting point can be multiple.   
>	Change queue to static, and add all starting points, and do BFS.

#1697 End. (Hide and Seek)
>	DFS & BFS   
>	I used BFS to solve this problem. It took about 268ms.   
>	But, it can be solved to use DP. With that way, time can be reduced to 136ms.

#7569 End. (Tomato 3D)
>	DFS & BFS   
>	3D version of #7576. This is not hard, but too hassle.   
>	I think that this is not good problem.

#2206 End. (Move with breaking wall)
>	DFS & BFS   
>	This is very complex problem. I tried so hard to solve this.   
>	I wrote about 138 lines, I think too spaghetti.   
>	I can shorten the code, but I think it will take so much times.   
>	Too complex, I wrote annotate at the code.

***
### Day 48
#7562 End. (Night Move)
>	DFS & BFS   
>	Ordinary BFS problem.

#1707 Fail. (Bipartite Graph)
>	DFS & BFS   
>	I tried to solve this with BFS, but time exceeded about 11%.   
>	I'll use DFS to solve this.

***
### Day 49
#1707 End. (Bipartite Graph)
>	DFS & BFS   
>	I used DFS to solve this. And it worked very well. Even the code was very short.

#1753 End. (Shortest Path)
>	Dijkstra   
>	First, I enque ( Vertex , Length of Edge ). And it fails about 12%.   
>	I passed every counterexample, and people said that have to enque cumulative length.   
>	I couldn't find the reason why I fail, so I just changed to enque cumulative length. And it passed.

#1504 Fail. (Specific Shortest Path)
>	Dijkstra   
>	I tried to solve this with Dijkstra, similar as #1753. But it failed about 12%.   
>	I'll find the reason and fix this.