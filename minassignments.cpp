#include <iostream>
using namespace std;
class course_details{
    public:
        int grade;
        int min_assignments_req;
};

course_details* combined(course_details* arr1c,int len1,course_details* arr2c, int len2){
        int arr1_index=0,arr2_index=0,new_array_index= 0;
        course_details* output = new course_details[len1+len2];
        while(new_array_index<len1+len2){
            if(arr1_index<len1 &&(arr2_index==len2|| (arr1c[arr1_index]).min_assignments_req<arr2c[arr2_index].min_assignments_req)){
                
                output[new_array_index] = arr1c[arr1_index];
                arr1_index++;
                new_array_index++;

            }
            else{
                output[new_array_index]= arr2c[arr2_index];
                arr2_index++;
                new_array_index++;
            }
        }
        
        return output;
    }
course_details* merge_sort(course_details* array,int len){//end exclusive
   if (len==1){
        
        return array;
    }
    
    if(len%2){
        course_details* arr1= new course_details[len/2+1];
        course_details* arr2 = new course_details[len/2];
        for(int i=0;i<len;i++){
            
            if(i<len/2+1){
                arr1[i] = array[i];
            }
            else{
                arr2[i-len/2-1]= array[i];
            }
        }
        return combined(merge_sort(arr1,len/2+1),len/2+1,merge_sort(arr2,len/2),len/2);
    }




    
    else{
        course_details* arr1= new course_details[len/2];
        course_details* arr2 = new course_details[len/2];
        for(int i=0;i<len;i++){
            
            if(i<len/2){
                arr1[i] = array[i];
            }
            else{
                arr2[i-len/2]= array[i];
            }
        }
        return combined(merge_sort(arr1,len/2),len/2,merge_sort(arr2,len/2),len/2);
    }

}
int sum_grades(course_details* array,int len){
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=array[i].grade;
    }
    return sum;
}
int main(){
    int n_courses,max_grade,average_grade;
    cin>>n_courses>>max_grade>>average_grade;
    average_grade*=n_courses;//now avg grade signifies required grade
    course_details* courses_list = new course_details[n_courses];
    for(int i=0;i<n_courses;i++){
        cin>>(courses_list[i].grade)>>courses_list[i].min_assignments_req;

    }
    course_details* sorted_courses_list = merge_sort(courses_list,n_courses);
    delete[] courses_list;
    int sum = sum_grades(sorted_courses_list,n_courses);
    if(sum<average_grade){
        int diff = average_grade-sum;
        int assgn_count=0;
        int course_no=0;
        while(diff>0 && course_no<n_courses){
            
            while(sorted_courses_list[course_no].grade<max_grade){
                assgn_count+=sorted_courses_list[course_no].min_assignments_req;
                sorted_courses_list[course_no].grade++;
                diff--;
                if(!diff){
                    break;
                }
            }
            course_no++;
        }
        cout<<assgn_count<<"\n";
    }
    else{
        cout<<"BOO"<<0<<"\n";
    }
    
    
}