 #include <stdio.h>
 int main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];
    printf("\nEnter total memory size: ");
    scanf("%d", &ms);
    printf("Enter page size: ");
    scanf("%d", &ps);
    nop = ms / ps;
    printf("Total number of pages: %d\n", nop);
    printf("\nEnter number of processes: ");
    scanf("%d", &np);
    rempages = nop;
    for (i = 1; i <= np; i++) {
        printf("\nEnter number of pages required for process [%d]: ", i);
        scanf("%d", &s[i]);
        if (s[i] > rempages) {
            printf("Memory full! Cannot allocate pages for process %d.\n", i);
            break;
        }
        rempages -= s[i];
        printf("Enter frame numbers for process [%d]:\n", i);
        for (j = 0; j < s[i]; j++) {
            printf(" Page %d -> Frame: ", j);
            scanf("%d", &fno[i][j]);
        }
    }
    printf("\nEnter process number, page number, and offset: ");
    scanf("%d %d %d", &x, &y, &offset);
    if (x > np || y >= s[x] || offset >= ps)
        printf("\nInvalid input!\n");
    else {
        pa = fno[x][y] * ps + offset;
        printf("\nPhysical Address = %d\n", pa);
    }
    return 0;
 }
