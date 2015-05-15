#insertion sort an array

#first, fix the value at the second position of an array using a key pointer, and compare it with the previous value, 
#if it is less than the previous value, then swap, otherwise break. then the pointer point to the next until to the end of the array

def insertion_sort(list):
	for i in range(1,len(list)):
		value=list[i]
		k=i
		while k>=1:
			if value<list[k-1]:
				list[k]=list[k-1]
				list[k-1]=value
				k=k-1
			else:
				break
			
	print list
	
insertion_sort([5,3,2,1])
