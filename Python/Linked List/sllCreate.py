from node import node

def makeSLL_string(data: str, func: type = str) -> node:
    """
    Creates a Single Linked List from space separated string
    Each space separated token of the string is considered as a node in the linked list

    Parameters
    ----------
    data: str
        Space separated string data
    func: type
        * This argument accepts a function and used in map function\n
        * This argument is applied to every token of the input data\n
        * Default Value is str\n
        * Prior Knowledge about data is required before
        passing this argument as it can lead to Exception
    
    If complex data is passed. It's better to use makeSLL_list() function

    Returns
    ----------
    node
        Head node of the Single Linked List
    
    """
    dummyHead = curr = node()   # Dummy Head
    print(type(func))

    for token in map(func, data.strip().split()):
        curr.next = node(token)
        curr = curr.next
    
    realHead = dummyHead.next
    dummyHead.next = None

    return realHead

def makeSLL_list(data: list) -> node:
    """
    Creates a Single Linked List from list
    Each element of the list is considered as a node in the linked list

    Parameters
    ----------
    data: list
        List containg elements with various data types
    

    Returns
    ----------
    node
        Head node of the Single Linked List
    
    """
    dummyHead = curr = node()   # Dummy Head

    for token in data:
        curr.next = node(token)
        curr = curr.next
    
    realHead = dummyHead.next
    dummyHead.next = None

    return realHead
