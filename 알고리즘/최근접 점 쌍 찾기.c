
void who_min(point temp[], int size) {
    double check;
    if (size == 2) {
        check = distance(temp[0], temp[1]); // ���� ���� ���
        if (min < check && min != -1.0) return;
        min = check;
        min_p[0] = temp[0];
        min_p[1] = temp[1];
    }
    else {
        double dis[3] = { 0 }; // 3���� �����Ÿ� ����

        for (int i = 0; i < size; i++) { // 3���� �����Ÿ� ���ϱ�
            if (i == 2) dis[i] = distance(temp[i], temp[0]);
            else dis[i] = distance(temp[i], temp[i + 1]);
        }

        // �� ���� �Ÿ� ����
        check = dis[0] < dis[1] ? dis[0] : dis[1];
        check = check < dis[2] ? check : dis[2];

        if (min != -1.0 && min < check) return;
        min = check;

        // �� ���� �Ÿ� ���� ����
        for (int i = 0; i < 3; i++) { // 3���� �����Ÿ� ���ϱ�
            if (min == dis[i]) {
                if (i == 2) min_p[0] = temp[i], min_p[1] = temp[0];
                else min_p[0] = temp[i], min_p[1] = temp[i + 1];
            }
        }
    }
}