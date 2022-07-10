# Implementations of Node in Linked List
# Single Linked List

class node():
    """
        class to represent the individual Nodes of the single linked list
        
        Attributes
        ----------
            * value: any
                * Represents the data value of the node
                * can be any type
                * default value is None
            * next: node
                * attribute to store the next node reference
    """
    
    def __init__(self, value:any = None, next = None):
        self.value = value
        self.next = next
        self.__selfAddr = (hex(id(self)),)

    def __str__(self) -> str:
        return str(self.value)

    def debugInfo(self) -> tuple:
        return (self.value, self.__selfAddr, None if self.next is None else (hex(id(self.next)),))


