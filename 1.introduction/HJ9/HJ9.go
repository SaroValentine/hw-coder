package main
/*
https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=1&judgeStatus=undefined&tags=&title=
*/
import (
    "fmt"
)

func main() {
    a := 0
    for {
        n, _ := fmt.Scan(&a)
        if(n==0){
            break
        }
        sum := 0
        hash := make(map[int]bool,0)
        for ;a>0;a/=10{
            if _,ok := hash[a%10];!ok{
                sum = sum * 10 + a%10
                hash[a%10] = true
            }

        }
        fmt.Println(sum)
    }
    return
}