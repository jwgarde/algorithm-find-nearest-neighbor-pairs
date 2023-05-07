
void who_min(point temp[], int size) {
    double check;
    if (size == 2) {
        check = distance(temp[0], temp[1]); // 제일 작은 경우
        if (min < check && min != -1.0) return;
        min = check;
        min_p[0] = temp[0];
        min_p[1] = temp[1];
    }
    else {
        double dis[3] = { 0 }; // 3개의 직선거리 저장

        for (int i = 0; i < size; i++) { // 3개의 직선거리 구하기
            if (i == 2) dis[i] = distance(temp[i], temp[0]);
            else dis[i] = distance(temp[i], temp[i + 1]);
        }

        // 젤 작은 거리 저장
        check = dis[0] < dis[1] ? dis[0] : dis[1];
        check = check < dis[2] ? check : dis[2];

        if (min != -1.0 && min < check) return;
        min = check;

        // 젤 작은 거리 점들 저장
        for (int i = 0; i < 3; i++) { // 3개의 직선거리 구하기
            if (min == dis[i]) {
                if (i == 2) min_p[0] = temp[i], min_p[1] = temp[0];
                else min_p[0] = temp[i], min_p[1] = temp[i + 1];
            }
        }
    }
}