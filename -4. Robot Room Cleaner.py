# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        x, y = [1, 0, -1, 0], [0, 1, 0, -1]
        turn = 0
        visit = set()
        def helper(i, j):
            nonlocal turn
            turn_copy = turn
            robot.clean()
            visit.add((i, j))
            for _ in range(4):
                i_new, j_new = i + x[turn % 4], j + y[turn % 4]
                if (i_new, j_new) not in visit and robot.move():
                    helper(i_new, j_new)
                    robot.move()
                    robot.turnLeft()
                    robot.turnLeft()
                    turn += 2
                robot.turnLeft()
                turn += 1
            while (turn - turn_copy) % 4 != 2:
                robot.turnLeft()
                turn += 1
        return helper(0, 0)