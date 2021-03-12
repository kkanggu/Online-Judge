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