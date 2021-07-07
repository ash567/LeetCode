import heapq
​
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        tupleList = [(tasks[i][0], tasks[i][1], i) for i in range(len(tasks))]
        tupleList.sort()
        hq = []
        nextEvent = 0
        i = 0
        ans = []
        while len(ans) < len(tasks):
            while(i < len(tupleList) and tupleList[i][0] <= nextEvent):
                heapq.heappush(hq, (tupleList[i][1], tupleList[i][2]))
                i += 1;
            if(len(hq) == 0):
                nextEvent = tupleList[i][0]
                continue
            duration, index = heapq.heappop(hq)
            ans += [index]
            nextEvent += duration
        return ans
