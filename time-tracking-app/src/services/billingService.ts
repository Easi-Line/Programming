export class BillingService {
    private billingRecords: Billing[] = [];

    public calculateBilling(projectId: string, hourlyRate: number, hoursWorked: number): number {
        return hourlyRate * hoursWorked;
    }

    public addBillingRecord(billing: Billing): void {
        this.billingRecords.push(billing);
    }

    public getBillingReports(): Billing[] {
        return this.billingRecords;
    }
}

interface Billing {
    id: string;
    projectId: string;
    amount: number;
    billingDate: Date;
}