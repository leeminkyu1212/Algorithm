import sys
sys.setrecursionlimit(10**6) 

class Node:
  def __init__(self, x, y, idx):
    self.x = x
    self.y = y
    self.idx = idx
    self.left = None
    self.right = None


def insert_node(parent, child):
  if child.x < parent.x:
    if parent.left is None:
      parent.left = child
    else:
      insert_node(parent.left, child)
  else:
    if parent.right is None:
      parent.right = child
    else:
      insert_node(parent.right, child)


def preorder(node, result):
  if node is None:
    return
  result.append(node.idx)
  preorder(node.left, result)
  preorder(node.right, result)


def postorder(node, result):
  if node is None:
    return
  postorder(node.left, result)
  postorder(node.right, result)
  result.append(node.idx)


def solution(nodeinfo):
  nodes = [Node(x, y, idx + 1) for idx, (x, y) in enumerate(nodeinfo)]

  nodes.sort(key=lambda node: (-node.y, node.x))

  root = nodes[0]

  for node in nodes[1:]:
    insert_node(root, node)

  pre_result = []
  post_result = []

  preorder(root, pre_result)
  postorder(root, post_result)

  return [pre_result, post_result]