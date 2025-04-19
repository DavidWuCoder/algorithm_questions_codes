import numpy as np

class TreeNode:
    """回归树节点类"""
    def __init__(self, val=None, split_point=None, left=None, right=None):
        self.val = val          # 叶节点值（均值）
        self.split_point = split_point  # 切分点值
        self.left = left        # 左子树（<=切分点）
        self.right = right      # 右子树（>切分点）

def choose_best_split(sublist):
    """选择最佳切分点"""
    min_loss = float('inf')
    best_idx = 0
    best_val = None
    
    # 遍历所有可能的切分点
    for i in range(1, len(sublist)):  # 至少保留1个元素在左子集
        left = sublist[:i]
        right = sublist[i:]
        
        # 计算平方误差
        left_loss = np.var(left) * len(left) if left else 0
        right_loss = np.var(right) * len(right) if right else 0
        total_loss = left_loss + right_loss
        
        if total_loss < min_loss:
            min_loss = total_loss
            best_idx = i
            best_val = sublist[i-1]  # 取左区间最大值作为切分点[3](@ref)
            
    return best_idx, best_val, min_loss

def build_regression_tree(lst, min_samples=2, tol_error=1e-4):
    """
    优化后的CART回归树构建函数
    :param lst: 输入数据列表
    :param min_samples: 最小切分样本数（预剪枝条件）
    :param tol_error: 误差变化阈值（预剪枝条件）
    :return: TreeNode对象
    """

    # 基线误差（不切分时的误差）
    base_error = np.var(lst) * len(lst)
    
    # 预剪枝条件判断
    if len(lst) <= min_samples or base_error <= tol_error:
        return TreeNode(val=np.mean(lst))
    
    # 选择最佳切分点
    split_idx, split_val, split_loss = choose_best_split(lst)
    
    # 误差减少不足时停止分裂[7](@ref)
    if (base_error - split_loss) < tol_error:
        return TreeNode(val=np.mean(lst))
    
    # 递归构建子树
    left_sub = lst[:split_idx]
    right_sub = lst[split_idx:]
    
    node = TreeNode(split_point=split_val)
    node.left = build_regression_tree(left_sub, min_samples, tol_error)
    node.right = build_regression_tree(right_sub, min_samples, tol_error)
    
    return node

# 测试用例
if __name__ == "__main__":
    data = [4.5, 4.75, 4.91, 5.34, 5.80, 7.05, 7.90, 8.23, 8.70, 9.00]
    
    # 构建回归树（设置最小样本数=3）
    tree = build_regression_tree(data, min_samples=1)
    
    # 打印树结构（演示用）
    def print_tree(node, indent=0):
        if node.val is not None:
            return
        else:
            print('     ' * indent + f'Split at x <= {node.split_point:.2f}')
            print_tree(node.left, indent+1)
            print_tree(node.right, indent+1)
    
    print_tree(tree)