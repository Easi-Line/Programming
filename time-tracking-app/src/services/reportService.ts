export class ReportService {
    private reports: Report[] = [];

    public generateReport(projectId: string, content: string): Report {
        const report: Report = {
            id: this.generateId(),
            projectId,
            date: new Date(),
            content,
        };
        this.reports.push(report);
        return report;
    }

    public getReports(projectId: string): Report[] {
        return this.reports.filter(report => report.projectId === projectId);
    }

    private generateId(): string {
        return (Math.random() * 100000).toFixed(0);
    }
}