package main
import "fmt"

func main() {
    var N int
    fmt.Scanf("%d\n", &N)
    
    arr := make([]int, N)
    for i := 0; i < N; i += 1 {
        fmt.Scanf("%d", &arr[i])
    }
    fmt.Printf("%d", arr[N-1])
    for i := N - 2; i >= 0; i -= 1 {
        fmt.Printf(" %d", arr[i])
    }
    fmt.Println();
}