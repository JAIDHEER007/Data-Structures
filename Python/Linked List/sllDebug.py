def simpleDebug(head) -> None:
    """
        This is a simple debug function\n
        Simply prints the Linked List

        Parameters
        ----------
        head: node
            Head of the linked list
        
        Returns
        ----------
            Returns nothing
    """
    curr = head
    while curr is not None:
        print(curr, end = ' -> ')
        curr = curr.next
    print("END")

def advancedDebug(head) -> None:
    """
        This is a advanced debug function\n
        Prints the Linked List in the form of table
        The table contains NodeValue, NodeType, selfAddr, nextAddr
        * nextAddr should be same as selfAddr of the next node.

        Parameters
        ----------
        head: node
            Head of the linked list
        
        Returns
        ----------
            Returns nothing
    """

    nodeValues, nodeTypes, selfAddrs, nextAddrs = [], [], [], []

    curr = head
    nodeCnt = 0
    while curr is not None:
        nodeData = curr.debugInfo()
        nodeValues.append(str(nodeData[0]))
        nodeTypes.append(str(type(nodeData[0])))
        selfAddrs.append(str(nodeData[1][0]))
        nextAddrs.append(str(None if nodeData[2] is None else nodeData[2][0]))
        nodeCnt += 1

        curr = curr.next
    
    maxNV = max(max(map(len, nodeValues)) + 5, 16)
    maxT = max(max(map(len, nodeTypes)) + 5, 16)

    separator = '-' * (maxNV + maxT + 20 + 20 + 5)
    # Printing the header
    print(separator)
    print('|', 'Node Value'.center(maxNV, ' '), '|', 'Node Type'.center(maxT, ' '), 
          '|', 'Self Address'.center(20, ' '), '|', 'Next Address'.center(20, ' '), '|', sep='')
    print(separator)

    for i in range(nodeCnt):
        print('|', nodeValues[i].center(maxNV, ' '), '|', nodeTypes[i].center(maxT, ' '), 
              '|', selfAddrs[i].center(20, ' '), '|', nextAddrs[i].center(20, ' '), '|', sep='')
        print(separator)

