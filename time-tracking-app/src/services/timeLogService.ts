export class TimeLogService {
    private timeLogs: any[] = [];

    saveTimeLog(timeLog: any) {
        this.timeLogs.push(timeLog);
        return timeLog;
    }

    fetchTimeLogs() {
        return this.timeLogs;
    }

    deleteTimeLog(id: string) {
        this.timeLogs = this.timeLogs.filter(log => log.id !== id);
        return this.timeLogs;
    }
}