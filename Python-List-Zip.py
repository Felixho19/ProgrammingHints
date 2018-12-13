# Usage: zip(list1,list2)
# list1 = [a,b,c,d]
# list2 = [0,1,2,3]
# Out: [(a,0),(b,1),(c,2),(d,3)]
# Python2: zip return list
# Python3: zip return zip object

# Use case:
# Given a list A of n elements, check P,Q where 0<P<Q<N which satisfy A[P]!=A[Q] and no other element x in A is between A[P] and A[Q]. 
# Idenify minimun distance of adjancent indices
p = list(zip(Arr, range(len(Arr))))
p.sort()
