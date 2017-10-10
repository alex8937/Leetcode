"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution:
    def getDict(self, employees):
        return {e.id : e for e in employees}

    def getImportance(self, employees, id):
        """
        BFS search
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        empolyDict = self.getDict(employees)
        queue = [id]
        total_importance = 0
        while queue:
            length = len(queue)
            for _ in range(length):
                empolyee = empolyDict[queue.pop(0)]
                queue.extend(empolyee.subordinates)
                total_importance += empolyee.importance
        return  total_importance

    def getImportance(self, employees, id):
        """
        DFS search
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        empolyDict = self.getDict(employees)
        def importanceHelper(_id):
            employee = empolyDict[_id]
            return employee.importance + sum([importanceHelper(sub) for sub in employee.subordinates])
        return importanceHelper(id)
