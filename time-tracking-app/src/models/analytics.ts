export interface Analytics {
    id: string;
    projectId: string;
    date: Date;
    totalTimeSpent: number; // in minutes
    productivityScore: number; // a score representing productivity level
    notes?: string; // optional notes for additional context
}