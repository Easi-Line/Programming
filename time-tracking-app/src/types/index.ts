export interface TimeLog {
    id: string;
    projectId: string;
    startTime: Date;
    endTime: Date;
    description: string;
}

export interface Project {
    id: string;
    name: string;
    category: string;
    description: string;
}

export interface Report {
    id: string;
    projectId: string;
    date: Date;
    content: string;
}

export interface Analytics {
    id: string;
    projectId: string;
    totalTimeSpent: number;
    productivityScore: number;
}

export interface Billing {
    id: string;
    projectId: string;
    amount: number;
    billingDate: Date;
}